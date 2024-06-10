#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name)
    , _isSigned(false)
    , _signGrade(signGrade)
    , _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << _name << " constructor called" << std::endl;

}

AForm::AForm(const AForm &rhs)
    : _name(rhs._name)
    , _isSigned(rhs._isSigned)
    , _signGrade(rhs._signGrade)
    , _execGrade(rhs._execGrade)
{
    std::cout << _name << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &rhs)
{
    std::cout << _name << " copy assignment operator called" << std::endl;
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return (*this);
}

AForm::~AForm()
{
    std::cout << _name << " destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return (_name);
}

bool AForm::isSigned() const
{
    return (_isSigned);
}

int AForm::getSignGrade() const
{
    return (_signGrade);
}

int AForm::getExecGrade() const
{
    return (_execGrade);
}

void AForm::beSigned(Bureaucrat const &person)
{
    if (person.getGrade() > _signGrade)
        throw GradeTooLowException();
    // else if (_isSigned)
    //     throw _isSigned;
    _isSigned = true;
}

void AForm::checkExecuteRequirements(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("grade is too low!");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
    out << rhs.getName() << ", form sign status: "
        << std::boolalpha << rhs.isSigned()
        << ", signGrade: " << rhs.getSignGrade()
        << ", execGrade: " << rhs.getExecGrade()
        << std::endl;
    return (out);
}