#include "phonebook.hpp"

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
            phonebook.AddContact();
        else if (cmd == "SEARCH")
            phonebook.PrintInfo();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "wrong cmd!" << std::endl;
    }
    return (0);
}
