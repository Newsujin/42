#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> exchangeRates;

		bool is_number(const std::string& value);
		bool is_correct_date(const std::string& date);
		double get_exchange_rate(const std::string& date);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void init(const std::string& dataFile);
		void exchange(const std::string& inputFile);
};

#endif