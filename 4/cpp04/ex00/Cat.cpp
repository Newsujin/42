#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &rhs) : Animal(rhs) // 초기화리스트로 부모의 복사생성자를 호출하지 않아도 ok?
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = rhs;
}

Cat& Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    type = rhs.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "냥!" << std::endl;
}
