#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: wrong argc!\n";
		return (1);
	}

	try {
		BitcoinExchange btc;
		btc.parseDb("data.csv");
		btc.exchange(argv[1]);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}