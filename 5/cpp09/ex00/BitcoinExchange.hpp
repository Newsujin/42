#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
};

#endif