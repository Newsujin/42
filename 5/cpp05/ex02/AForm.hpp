#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
        
        AForm();
    
    public:
        AForm(const std::string &name, int signGrade, int execGrade);
        AForm(const AForm &rhs);
        AForm &operator=(const AForm &rhs);
        virtual ~AForm();

        std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat const &person);
        virtual void execute(Bureaucrat const & executor) const = 0;
    
        void checkExecuteRequirements(Bureaucrat const &executor) const;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif