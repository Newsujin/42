#ifndef INTERN_HPP
# define INTERN_HPP

// # include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &rhs);
        Intern &operator=(const Intern &rhs);
        ~Intern();

        AForm* makeForm(const std::string &formName, const std::string &target) const;

        class FormNotExistException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif
