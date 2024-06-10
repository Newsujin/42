#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat chim("chim", 1);
        Bureaucrat spark2("spark2", 50);

        Intern intern;
        AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        AForm* form3 = intern.makeForm("presidential pardon", "Ford Prefect");
        AForm* form4 = intern.makeForm("unknown form", "Unknown");

        std::cout << std::endl;

        if (form1) {
            try {
                chim.signForm(*form1);
                chim.executeForm(*form1);
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
            delete form1;
        }

        std::cout << std::endl;

        if (form2) {
            try {
                spark2.signForm(*form2);
                spark2.executeForm(*form2);
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
            delete form2;
        }

        std::cout << std::endl;

        if (form3) {
            try {
                chim.signForm(*form3);
                chim.executeForm(*form3);
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
            delete form3;
        }

        if (form4) {
            delete form4;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
