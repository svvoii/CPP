// Defining some ANSI escape codes for consol output colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cstdlib>
# include <algorithm>

const std::string			DATE_FORMAT = "YYYY-MM-DD";
//const std::string			DATA_FILE = "data_short.csv";
static const std::string	DATA_FILE = "data.csv";

class	BitcoinExchange {

	private:
		std::map<std::string, float>	_ratesBTC;

	public:
		std::string						line;
		std::string						yyyy_mm_dd;
		std::string						yyyy;
		std::string						mm;
		std::string						dd;
		std::string						value;

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);


		std::map<std::string, float> const &getRates(void) const;

		bool	isDateValid();
		bool	isValueValid();
		bool	isInputValueValid();
		void	saveHistoricalData();
		void	parseLine(std::string line);
		void	outputData();

};

#endif //BITCOINEXCHANGE_HPP

/*
** `std::map<std::string, float> const &getRates(void) const;`: is 
** a const method that returns a const reference to the map.
** 
*/