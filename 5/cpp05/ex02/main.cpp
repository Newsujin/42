#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat spark2("spark2", 50);
        Bureaucrat chim("chim", 1);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("AlphaGo");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\nTesting ShrubberyCreationForm with chim:" << std::endl;
        try {
            chim.signForm(shrubbery);
            chim.executeForm(shrubbery);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\nTesting ShrubberyCreationForm with spark2:" << std::endl;
        try {
            spark2.signForm(shrubbery);
            spark2.executeForm(shrubbery);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\nTesting RobotomyRequestForm with chim:" << std::endl;
        try {
            chim.signForm(robotomy);
            chim.executeForm(robotomy);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\nTesting RobotomyRequestForm with spark2:" << std::endl;
        try {
            spark2.signForm(robotomy);
            spark2.executeForm(robotomy);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\nTesting PresidentialPardonForm with chim:" << std::endl;
        try {
            chim.signForm(pardon);
            chim.executeForm(pardon);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\nTesting PresidentialPardonForm with spark2:" << std::endl;
        try {
            spark2.signForm(pardon);
            spark2.executeForm(pardon);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
