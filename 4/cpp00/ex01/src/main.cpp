#include "Phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string cmd;

    while (true)
    {
        std::cout << "please enter command: (ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            break;
        if (cmd == "ADD")
            phonebook.Add();
        else if (cmd == "SEARCH")
            phonebook.Search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << std::endl << "That's wrong command!" << std::endl;
    }
    return (0);
}
