#include "Serializer.hpp"

int	main()
{
	Data prev;
	Data *next;
	uintptr_t ptr;

	prev.value = "spark2";
	std::cout << "prev: " << prev.value << std::endl;

	ptr = Serializer::serialize(&prev);
	std::cout << "ptr: " << ptr << std::endl;

	next = Serializer::deserialize(ptr);
	std::cout << "next: " << next->value << std::endl;

	return (0);
}