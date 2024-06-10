#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145, 137)
    , _target(target)
{
    std::cout << getName() << " constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
    : AForm(rhs)
    , _target(rhs._target)
{
    std::cout << getName() << " copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << getName() << " destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    checkExecuteRequirements(executor);

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw FileException();
    
    std::string ascii =
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "       // \\\n";

    file << ascii;
    file.close();

    if (file.fail())
        throw FileException();
}

const char  *ShrubberyCreationForm::FileException::what(void) const throw()
{
	return ("File error");
}