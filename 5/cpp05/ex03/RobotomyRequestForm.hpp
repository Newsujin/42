#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        std::string getTarget() const;

        void execute(const Bureaucrat& executor) const;

        class RobotomyFailureException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif