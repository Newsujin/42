#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream dbFile(filename.c_str());
	if (!dbFile.is_open()) {
		std::cerr << "error: can not open db file!\n";
		// throw Error();
	}

	std::string line;
	if (std::getline(dbFile, line).eof()) {
		std::cout << "error: file empty!\n";
		// throw Error();
	}

	while (std::getline(dbFile, line)) {
		
	}
}
