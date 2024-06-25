#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: wrong argc!\n";
		return (1);
	}

	try {
		PmergeMe pmm(ac, av);

		pmm.printVec(BEFORE_SORT);
		clock_t vec_t = clock();
		pmm.fordJohnsonVec();
        vec_t = clock() - vec_t;
		pmm.printVec(AFTER_SORT);
        std::cout << "Time to process a range of " << ac - 1 << " element with std::vector : " << static_cast<float>(vec_t) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;

		clock_t deq_t = clock();
		pmm.printDeq(BEFORE_SORT);
		pmm.fordJohnsonDeq();
        deq_t = clock() - deq_t;
		pmm.printDeq(AFTER_SORT);
        std::cout << "Time to process a range of " << ac - 1 << " element with std::deque : " << static_cast<float>(deq_t) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}