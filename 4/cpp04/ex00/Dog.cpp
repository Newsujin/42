#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = rhs;
}

Dog& Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    type = rhs.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "멍!" << std::endl;
}
