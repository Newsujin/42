#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream dbFile(filename.c_str());
	if (!dbFile.is_open()) {
		std::cerr << "Error: can not open db file!";
		// throw Error();
	}

	std::string line;
	if (std::getline(dbFile, line).eof()) {
		std::cout << "Error: file empty!";
		// throw Error();
	}

	while (std::getline(dbFile, line)) {
		std::istringstream iss(line); // 문자열을 입력 스트림으로 변환
		std::string date;
		float price;
		char comma;
		if (iss >> date >> comma >> price && comma == ',')
			_bitcoinPrice[date] = price;
	}
}

void BitcoinExchange::processTransaction(const std::string& date, float value) const {
	if (value < 0 || value > 1000) {
		std::cerr << "Error: invalid number!";
		// throw Error;
	}

	// db에서 날짜 검색
	std::map<std::string, float>::const_iterator it = _bitcoinPrice.lower_bound(date);
	// 입력된 값이 date 보다 크거나 같은 날짜가 없는 경우
	if (it == _bitcoinPrice.end() || it->first != date) {
		// date 보다 작은 요소가 db에 없는 경우
		if (it == _bitcoinPrice.begin()) {
			std::cerr << "Error: date not found!";
			// throw Error;
		}
	}
}