#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &rhs) : Animal(rhs) // 부모 복사생성자 호출 안 해도 되는지
{
    std::cout << "Dog copy constructor called" << std::endl;
    // brain = new Brain(*rhs.brain); // 없는 게 맞는지
    *this = rhs;
}

Dog& Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    if (brain)
        delete brain;
    type = rhs.type;
    brain = new Brain(*(rhs.brain));
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "멍!" << std::endl;
}

std::string Dog::getDogIdea(int idx) const
{
    if (idx >= 0 && idx < 100)
        return (brain->getIdeas()[idx]);
    return ("exceed brain capacity!");
}

void Dog::setDogIdea(int idx, std::string idea)
{
	if (idx < 0 || idx > 99)
	{
		std::cout << "exceed brain capacity!" << std::endl;
		return ;
	}
	brain->setIdea(idx, idea);
}