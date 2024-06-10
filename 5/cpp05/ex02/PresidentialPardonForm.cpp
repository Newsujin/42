#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardon", 25, 5)
    , _target(target)
{
    std::cout << getName() << " constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
    : AForm(rhs)
    , _target(rhs._target)
{
    std::cout << getName() << " copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << getName() << " destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkExecuteRequirements(executor);

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
