#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _bitcoinPrice;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void processTransaction(const std::string& date, float value) const;
};

#endif