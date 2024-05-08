#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    type = rhs.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "엥?" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}