#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main() {
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		Base* ptr = generate();
		identify(ptr);
		identify(*ptr);

		delete ptr;
		std::cout << "-\n";
	}
	return (0);
}

Base* generate() {
	int	randValue = rand() % 3;

	if (randValue == 0)
		return new A;
	else if (randValue == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown type\n";
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (const std::exception& e) {}
}