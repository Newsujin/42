#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy", 72, 45)
    , _target(target)
{
    srand(time(0));
    std::cout << getName() << " constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
    : AForm(rhs)
    , _target(rhs._target)
{
    std::cout << getName() << " copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << getName() << " destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkExecuteRequirements(executor);

    std::cout << "BZZZZZZZ..." << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        throw RobotomyFailureException();
}

const char* RobotomyRequestForm::RobotomyFailureException::what() const throw()
{
    return ("robotomy failed!");
}