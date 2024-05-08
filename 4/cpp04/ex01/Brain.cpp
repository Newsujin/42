#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "empty";
}

Brain::Brain(std::string idea)
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = idea;
}

Brain::Brain(const Brain& rhs)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = rhs;
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < 100; i++)
        ideas[i] = rhs.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string *Brain::getIdeas()
{
    return (ideas);
}

void Brain::setIdea(int idx, std::string idea)
{
    ideas[idx] = idea;
}