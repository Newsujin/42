#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

        Bureaucrat();
        
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(Bureaucrat const &rhs);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void upGrade();
        void downGrade();
        void signForm(Form &rhs);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif