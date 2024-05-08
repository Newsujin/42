#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = rhs;
}

Animal& Animal::operator=(const Animal &rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    type = rhs.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}