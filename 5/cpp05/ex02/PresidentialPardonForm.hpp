#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

        PresidentialPardonForm();

    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& rhs);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm();

        std::string getTarget() const;

        void execute(const Bureaucrat& executor) const;
};

#endif