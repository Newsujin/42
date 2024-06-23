#include "RPN.hpp"

void f() {
	system("leaks RPN");
}
int main(int argc, char **argv) {
	atexit(f);
	if (argc != 2) {
		std::cerr << "error: wrong argc!\n";
		return (1);
	}

	try {
		RPN calculator;
		std::string input(argv[1]);
		calculator.execute(input);
		int result = calculator.getResult();
		std::cout << result << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}