/*
** This program is a simple Bitcoin exchange rate calculator.
**
** The program takes a date as input and returns the exchange rate of Bitcoin
** on that date.
**
** First the program reads the historical data from a file and stores it in a
** map. The map is sorted by date.
*/

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange exchange;

	if (argc != 2) {
		std::cout << RED << "Wrong arguments. Usage:" << RESET << std::endl;
		std::cout << GREEN << "btc input.txt" << RESET << std::endl;
		return 1;
	}
	else {
		exchange.saveHistoricalData();

		std::string		line;
		bool			firstLine = true;
		std::ifstream	file(argv[1]);

		if (file.is_open()) {

			while (getline(file, line)) {

				if (firstLine) {
					firstLine = false;
					continue;
				}
				if (!line.empty()) {
					exchange.parseLine(line);
				}
			}
			file.close();
		}
		else {
			std::cout << "Error: could not open file." << std::endl;
			return 1;
		}
	}

	//exchange.outputData();

	return 0;
}
