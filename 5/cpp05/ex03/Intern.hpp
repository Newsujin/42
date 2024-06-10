#ifndef INTERN_HPP
# define INTERN_HPP

// # include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm *Intern::createShrubbery(const std::string &target);
        AForm *Intern::createRobotomy(const std::string &target);
        AForm *Intern::createPresidential(const std::string &target);

    public:
        Intern();
        Intern(const Intern &rhs);
        Intern &operator=(const Intern &rhs);
        ~Intern();

        AForm* makeForm(const std::string &formName, const std::string &target);

        class FormNotExistException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif
