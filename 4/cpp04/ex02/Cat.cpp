#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &rhs) : Animal(rhs) // 부모 복사생성자 호출 안 해도 되는지
{
    std::cout << "Cat copy constructor called" << std::endl;
    // brain = new Brain(*rhs.brain); // 없는 게 맞는지
    *this = rhs;
}

Cat& Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    if (brain)
        delete brain;
    type = rhs.type;
    brain = new Brain(*(rhs.brain));
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "냥!" << std::endl;
}

std::string Cat::getCatIdea(int idx) const
{
    if (idx >= 0 && idx < 100)
        return (brain->getIdeas()[idx]);
    return ("exceed brain capacity!");
}

void Cat::setCatIdea(int idx, std::string idea)
{
	if (idx < 0 || idx > 99)
	{
		std::cout << "exceed brain capacity!" << std::endl;
		return ;
	}
	brain->setIdea(idx, idea);
}