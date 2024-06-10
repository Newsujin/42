#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = rhs;
}

Intern &Intern::operator=(const Intern &rhs) {
    if (this != &rhs)
        std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    AForm* form = nullptr;

    try {
        if (formName == "shrubbery creation") {
            form = new ShrubberyCreationForm(target);
        } else if (formName == "robotomy request") {
            form = new RobotomyRequestForm(target);
        } else if (formName == "presidential pardon") {
            form = new PresidentialPardonForm(target);
        } else {
            throw FormNotExistException();
        }
        std::cout << "Intern creates " << formName << " form" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Intern couldn't create form because " << e.what() << std::endl;
    }

    return form;
}

const char* Intern::FormNotExistException::what() const throw() {
    return "form doesn't exist!";
}
