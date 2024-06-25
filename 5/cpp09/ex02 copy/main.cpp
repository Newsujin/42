#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: wrong argc!\n";
		return (1);
	}

	try {
		PmergeMe pmm(ac, av);
		pmm.printInput(BEFORE_SORT);
		pmm.mergeInsertVec();
		pmm.mergeInsertDeq();
		pmm.printInput(AFTER_SORT);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}