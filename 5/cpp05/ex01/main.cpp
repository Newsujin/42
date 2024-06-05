#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat employee("employee", 100);
    Bureaucrat leader("leader", 1);
    Form planA("planA", 30, 150);
    Form planB("planB", 100, 150);
    
    std::cout << "======================================================\n";
    try
    {
        std::cout << planA;
        employee.signForm(planA);
        std::cout << planA;
		leader.signForm(planA);
        std::cout << planA;
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    
    std::cout << "======================================================\n";
    try
    {
        std::cout << planB;
        employee.signForm(planB);
        std::cout << planB;
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << "======================================================\n";
}