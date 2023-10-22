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

int main()
{
	BitcoinExchange exchange;

	exchange.saveHistoricalData();
	exchange.outputData();

	return 0;
}
