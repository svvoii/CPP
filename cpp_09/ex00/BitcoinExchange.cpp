#include "BitcoinExchange.hpp"

/* 
** This is the constructor definition which is called when an object is created.
** It is used to initialize the data members of the new object.
*/
BitcoinExchange::BitcoinExchange(void) : 
	yyyy_mm_dd("Date"), 
	value("Value") {
}

/*
** This is the copy constructor definition which is called when an object is created
** from another object of the same type.
*/
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void) {
}

/*
** This is the assignment operator definition which is called when an object is assigned
** the value of another object of the same type.
BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		yyyy_mm_dd = rhs.yyyy_mm_dd;
		value = rhs.value;
		ratesMap = rhs.ratesMap;
	}
	return *this;
}
*/

bool	BitcoinExchange::isDateValid() {

	size_t			invalidCharIndex = 0;
	size_t			dashPosition = 0;

	invalidCharIndex = yyyy_mm_dd.find_first_not_of("0123456789-");

	if (invalidCharIndex != std::string::npos) {
		std::cout << "Error: Date contains invalid characters" << std::endl;
		return false;
	}

	dashPosition = yyyy_mm_dd.find("-");
	yyyy = yyyy_mm_dd.substr(0, dashPosition);
	mm = yyyy_mm_dd.substr(dashPosition + 1, 2);
	dd = yyyy_mm_dd.substr(dashPosition + 4, 2);

	if (yyyy.length() != 4 || mm.length() != 2 || dd.length() != 2) {
		std::cout << "Error: Date is not in the correct format" << std::endl;
		return false;
	}
	else if (atoi(mm.c_str()) < 1 || atoi(mm.c_str()) > 12) {
		std::cout << "Error: Date is not in the correct range" << std::endl;
		return false;
	}
	else if (atoi(dd.c_str()) < 1 || atoi(dd.c_str()) > 31) {
		std::cout << "Error: Date is not in the correct range" << std::endl;
		return false;
	}
	return true;
}

/*
** `find_first_not_of` function is a member function of the `std::string class`,
** it returns the index of the first character in the string that does not match 
** any of the characters in the specified set, in this case: `"0123456789-"`
**
** So, the `index` variable will contain the index of the first character in the
** string that does not match any of the characters in `"0123456789-"`, or
** `std::string::npos` if no such character is found.
**
** `std::string::npos` is a static member constant value with the greatest possible
** value for an element of type `size_t`. In this case, it is `18446744073709551615`.
*/

bool	BitcoinExchange::isValueValid() {

	size_t	invalidCharIndex = value.find_first_not_of("0123456789.");

	if (value == "") {
		std::cout << "Error: Value is missing" << std::endl;
		return false;
	}
	else if (invalidCharIndex != std::string::npos) {
		std::cout << "Error: Value contains invalid characters" << std::endl;
		return false;
	}
	else if (atof(value.c_str()) < 0) {
		std::cout << "Error: Value must be a positive number" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isInputValueValid() {

	size_t	invalidCharIndex = value.find_first_not_of("0123456789.-");

	if (invalidCharIndex != std::string::npos) {
		std::cout << "Error: Input value contains invalid characters [" << value << "]" << std::endl;
		return false;
	}
	value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());

	if (value.empty()) {
		std::cout << "Error: Input value is missing" << std::endl;
		return false;
	}
	if (value.length() > 10 || (value.length() == 10 && atoi(value.c_str()) > 2147483647)) {
		std::cout << "Error: Input value is too large [" << value << "]" << std::endl;
		return false;
	}
	else if (atof(value.c_str()) < 0) {
		std::cout << "Error: Input value must be a positive number [" << value << "]" << std::endl;
		return false;
	}
	else if (atof(value.c_str()) > 1000) {
		std::cout << "Error: Input value is too large [" << value << "]" << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::saveHistoricalData() {

	std::ifstream	file(DATA_FILE.c_str());
	size_t	comaPosition = 0;

	if (file.is_open()) {

		while (getline(file, line)) {
			if (!line.empty() && (line.find_first_not_of("0123456789-,.|") == std::string::npos)) {
				comaPosition = line.find(",");
				this->yyyy_mm_dd = line.substr(0, comaPosition);
				this->value = line.substr(comaPosition + 1, std::string::npos);
				/* DEBUG */
				//std::cout << "\t[" << this->yyyy_mm_dd << "] | [" << this->value << "]" << std::endl;
				/* ****** */
				if (isDateValid() && isValueValid()) {
					_ratesBTC.insert(std::pair<std::string, float>(yyyy_mm_dd, atof(value.c_str())));
				}
			}
		}
		file.close();
	}
	else {
		std::cout << "Error: Unable to open file" << std::endl;
		exit(1);
	}

}

void	BitcoinExchange::parseLine(std::string line) {

	size_t	invalidCharIndex = line.find_first_not_of("0123456789-,.| ");
	size_t	posSeparator = line.find("|");
	float	result = 0;

	if (invalidCharIndex != std::string::npos || posSeparator == std::string::npos) {
		// std::cout << "Error: Input line is not in the correct format: [" << line << "]" << std::endl;
		std::cout << RED << "Error: Bad input.. => " << RESET << line << std::endl;
		return ;
	}
	yyyy_mm_dd = line.substr(0, posSeparator);
	value = line.substr(posSeparator + 1, std::string::npos);
	yyyy_mm_dd.erase(std::remove_if(yyyy_mm_dd.begin(), yyyy_mm_dd.end(), ::isspace), yyyy_mm_dd.end());
	value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
	if (isDateValid() == false || isInputValueValid() == false) {
		return ;
	}
	else {
		std::string	key = yyyy_mm_dd;
		if (this->_ratesBTC.count(key) != 0) {
			float	rate = _ratesBTC[key];
			result = rate * atof(value.c_str());
			std::cout << yyyy_mm_dd << " => " << value << " BTC =\t" << result << "\tEUR" << std::endl;
		}
		else {
			std::map<std::string, float>::iterator it;
			it = this->_ratesBTC.lower_bound(this->yyyy_mm_dd);
			if (it == this->_ratesBTC.begin()) {
				std::cout << "Error: No data available befor this date [" << this->yyyy_mm_dd << "]" << std::endl;
				return ;
			}
			else if (it == this->_ratesBTC.end()) {
				std::cout << "Error: No data available after this date [" << this->yyyy_mm_dd << "]" << std::endl;
				return ;
			}
			else {
				--it;
				result = it->second * atof(value.c_str());
				std::cout << yyyy_mm_dd << " => " << value << " BTC =\t" << result << "\tEUR" << std::endl;
			}
		}
	}
}

void	BitcoinExchange::outputData() {

	std::map<std::string, float>::iterator it;

	for (it = this->_ratesBTC.begin(); it != this->_ratesBTC.end(); ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}
