#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
    , _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << _name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
    : _name(rhs._name)
    , _grade(rhs._grade)
{
    std::cout << _name << " copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << _name << " copy assignment operator called" << std::endl;
    if (this != &rhs)
        _grade = rhs._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << _name << " destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::upGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::downGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &rhs)
{
    try
    {
        rhs.beSigned(*this);
        std::cout << _name << " signed " << rhs.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std:: cout << _name << " couldn't sign " << rhs.getName() << " because " << e.what() << std::endl;
    }
    // catch(bool sign)
    // {
    //     std::cout << rhs.getName() << " was already signed" << std::endl;
    // }
}

void Bureaucrat::executeForm(AForm const &rhs)
{
    try
    {
        rhs.execute(*this);
        std::cout << _name << " executed " << rhs.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std:: cout << _name << " couldn't execute " << rhs.getName() << " because " << e.what() << std::endl;
    }
    
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", " << rhs.getGrade() << std::endl;
    return (out);
}