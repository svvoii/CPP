#include "BitcoinExchange.hpp"

/* 
** This is the constructor definition which is called when an object is created.
** It is used to initialize the data members of the new object.
*/
BitcoinExchange::BitcoinExchange(void) : _date("Date"), _value("Value") {
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
*/
BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		_date = rhs._date;
		_value = rhs._value;
		_ratesMap = rhs._ratesMap;
	}
	return *this;
}

bool	BitcoinExchange::isDateValid() {

	size_t			index;
	size_t			position;
	std::string		year;
	std::string		month;
	std::string		day;
	std::string		tmp;

	index = _date.find_first_not_of("0123456789-");
	position = _date.find("-");
	year = _date.substr(0, position);
	tmp = _date.substr(position + 1);
	position = tmp.find("-");
	month = tmp.substr(0, position);
	day = tmp.substr(position + 1, 2);

	if (_date == "Date") {
		std::cout << "Error: Date is missing" << std::endl;
		return false;
	}
	else if (index != std::string::npos) {
		std::cout << "Error: Date contains invalid characters" << std::endl;
		return false;
	}
	else if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
		std::cout << "Error: Date is not in the correct format" << std::endl;
		return false;
	}
	else if (std::stoi(year) < 2009 || std::stoi(year) > 2021) {
		std::cout << "Error: Date is not in the correct range" << std::endl;
		return false;
	}
	else if (std::stoi(month) < 1 || std::stoi(month) > 12) {
		std::cout << "Error: Date is not in the correct range" << std::endl;
		return false;
	}
	else if (std::stoi(day) < 1 || std::stoi(day) > 31) {
		std::cout << "Error: Date is not in the correct range" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValueValid() {

	size_t	index;
	
	index = _value.find_first_not_of("0123456789.");
	if (_value == "Value") {
		std::cout << "Error: Value is missing" << std::endl;
		return false;
	}
	else if (index != std::string::npos) {
		std::cout << "Error: Value contains invalid characters" << std::endl;
		return false;
	}
	else if (std::stof(_value) < 0) {
		std::cout << "Error: Value must be a positive number" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isInputValueValid() {

	size_t	index;

	index = _value.find_first_not_of("0123456789.-");

	if (index != std::string::npos) {
		std::cout << "Error: Input value contains invalid characters" << std::endl;
		return false;
	}
	_value.erase(std::remove_if(_value.begin(), _value.end(), ::isspace), _value.end());

	if (_value.empty()) {
		std::cout << "Error: Input value is missing" << std::endl;
		return false;
	}
	if (_value.length() > 10 || (_value.length() == 10 && std::stoi(_value) > 2147483647)) {
		std::cout << "Error: Input value is too large" << std::endl;
		return false;
	}
	else if (std::stof(_value) < 0) {
		std::cout << "Error: Input value must be a positive number" << std::endl;
		return false;
	}
	else if (std::stof(_value) > 1000) {
		std::cout << "Error: Input value is too large" << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::saveHistoricalData() {

	std::ifstream	csvFile("data.csv");
	std::string		line;
	unsigned int	position;

	if (csvFile.is_open()) {

		while (getline(csvFile, line)) {

			if (!line.empty()) {
				position = line.find(",");
				_date = line.substr(0, position);
				_value = line.substr(position + 1, std::string::npos);
				if (isDateValid() && isValueValid()) {
					_ratesMap.insert(std::pair<std::string, float>(_date, std::stof(_value)));
				}
			}
		}
		csvFile.close();
	}
	else {
		std::cout << "Error: Unable to open file" << std::endl;
		exit(1);
	}

}

void	BitcoinExchange::parseLine(std::string line) {

	size_t	position = line.find("|");
	float	result = 0;

	if (position == std::string::npos) {
		std::cout << "Error: Input line is not in the correct format: [" << line << "]" << std::endl;
		return ;
	}
	_date = line.substr(0, position);
	_value = line.substr(position + 1, std::string::npos);
	_date.erase(std::remove_if(_date.begin(), _date.end(), ::isspace), _date.end());
	if (isDateValid() == false || isInputValueValid() == false) {
		std::cout << "Error: wrong input" << std::endl;
		return ;
	}
	else {
		std::string	key = _date;
		if (this->_ratesMap.count(key) != 0) {
			float	rate = _ratesMap[key];
			result = rate * std::stof(_value);
			std::cout << _date << " | " << _value << " BTC = " << result << " EUR" << std::endl;
		}
		else {
			std::map<std::string, float>::iterator it;
			it = this->_ratesMap.lower_bound(this->_date);
			if (it == this->_ratesMap.begin()) {
				std::cout << "Error: No data available befor this date" << std::endl;
				return ;
			}
			else if (it == this->_ratesMap.end()) {
				std::cout << "Error: No data available after this date" << std::endl;
				return ;
			}
			else {
				--it;
				result = it->second * std::stof(_value);
				std::cout << _date << " | " << _value << " BTC = " << result << " EUR" << std::endl;
			}
		}
	}
}

void	BitcoinExchange::outputData() {

	std::map<std::string, float>::iterator it;

	for (it = this->_ratesMap.begin(); it != this->_ratesMap.end(); ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}
