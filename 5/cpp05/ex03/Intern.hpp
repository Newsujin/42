#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm *createShrubbery(const std::string &target);
        AForm *createRobotomy(const std::string &target);
        AForm *createPresidential(const std::string &target);

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
