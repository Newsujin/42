#include "Serializer.hpp"

int main(void)
{
	Data prev;
	Data *next;
	uintptr_t ptr;


	prev.value = 1;
	std::cout << "prev : " << prev.value << std::endl;

	ptr = Serializer::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	next = Serializer::deserialize(ptr);
	std::cout << "next : " << next->value << std::endl;

	std::cout << "=========================================\n";

	// Data d;
	// Data *a;
	// uintptr_t memory;

	// d.value = "jaeyo";

	// memory = serialize(&d);
	// std::cout << "memory : " << memory << std::endl;

	// a = deserialize(memory);

	// std::cout << "a : " << a->value << std::endl;


	return (0);
}