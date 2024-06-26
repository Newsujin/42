#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# define uintptr_t unsigned long

struct Data {
	std::string value;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& rhs);
		Serializer& operator=(const Serializer& rhs);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif