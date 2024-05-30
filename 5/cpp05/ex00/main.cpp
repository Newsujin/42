#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("a", 0);
        // Bureaucrat a("a", 200);
        std::cout << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("b", 1);
        Bureaucrat c("c", 150);
        std::cout << b;
        std::cout << c;

        // b.upGrade();
        // c.downGrade();

        b.downGrade();
        c.upGrade();
        std::cout << b;
        std::cout << c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}