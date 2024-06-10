#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
    if (this != &rhs)
        std::cout << "Intern copy assignment operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"}; 
	AForm *(Intern::*createForm[3])(const std::string &) = {
		&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	AForm *result = NULL;

	try {
		for(int i = 0; i < 3; i++)
		{
			if (formNames[i] == formName)
			{
				result = (this->*createForm[i])(target);
				std::cout << "Intern creates " << result->getName() << "\n";
				return (result);
			}
		}
        throw FormNotExistException();
    } catch(const std::exception& e) {
        std::cout << "Intern couldn't create form because " << e.what() << std::endl;
    }

    return (result);
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

const char* Intern::FormNotExistException::what() const throw()
{
    return ("form doesn't exist!");
}
