#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		std::vector<int>::iterator it;
		it = easyfind(vec, 3);
		// it = easyfind(vec, 100);
		std::cout << *it << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int> lst;
		for (int i = 0; i < 10; i++)
			lst.push_back(i);

		std::list<int>::iterator it;
		it = easyfind(lst, 5);
		// it = easyfind(lst, 100);
		std::cout << *it << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}