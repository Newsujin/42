#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal(rhs)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    type = rhs.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "녕?" << std::endl;
}
