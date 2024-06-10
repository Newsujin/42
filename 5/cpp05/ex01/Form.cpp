#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
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

Form::Form(const Form &rhs)
    : _name(rhs._name)
    , _isSigned(rhs._isSigned)
    , _signGrade(rhs._signGrade)
    , _execGrade(rhs._execGrade)
{
    std::cout << _name << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &rhs)
{
    std::cout << _name << " copy assignment operator called" << std::endl;
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return (*this);
}

Form::~Form()
{
    std::cout << _name << " destructor called" << std::endl;
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_isSigned);
}

int Form::getSignGrade() const
{
    return (_signGrade);
}

int Form::getExecGrade() const
{
    return (_execGrade);
}

void Form::beSigned(Bureaucrat const &person)
{
    if (person.getGrade() > _signGrade)
        throw GradeTooLowException();
    // else if (_isSigned)
    //     throw _isSigned;
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
    out << rhs.getName() << ", form sign status: "
        << std::boolalpha << rhs.isSigned()
        << ", signGrade: " << rhs.getSignGrade()
        << ", execGrade: " << rhs.getExecGrade()
        << std::endl;
    return (out);
}