#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

class	BitcoinExchange {
private:
	std::string						_date;
	std::string						_value;
	std::map<std::string, float>	_ratesMap;

public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	BitcoinExchange	&operator=(BitcoinExchange const &rhs);

	std::map<std::string, float> const &getRates(void) const;

	bool	verifyDate();
	bool	verifyValue();
	bool	verifyInputValue();
	void	saveHistoricalData();
	void	evaluateLine(std::string line);
	void	outputData();

};

#endif //BITCOINEXCHANGE_HPP