#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: wrong argc!\n";
		return (1);
	}

	try {
		PmergeMe merge(ac, av);
		merge.printInput(BEFORE_SORT);
		merge.mergeInsertVec();
		merge.mergeInsertDeq();
		merge.printInput(AFTER_SORT);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}