#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm();

        std::string getTarget() const;

        void execute(const Bureaucrat& executor) const;

        class FileException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif