#include "contact.hpp"

int main()
{
    std::string cmd;
    while (true)
    {
        std::cout << "please enter command: (ADD, SEARCH, EXIT)" << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD")
        {

        }
        else if (cmd == "SERACH")
        {

        }
        else if (cmd == "EXIT")
        {

        }
        else
        {
            std::cout << "wrong cmd!" << std::endl;
        }
    }
    return (0);
}

void    PhoneBook::AddContact(void)
{
    this->contacts[idx % 8].AddInfo();
    this->idx++;
}

void    PhoneBook::PrintInfo()
{
    std::cout << "|" << std::setw(10) << "index"
            << "|" << std::setw(10) << "first name"
            << "|" << std::setw(10) << "last name"
            << "|" << std::setw(10) << "nick name"
            << "|" << std::endl;
    std::cout << "=================================" << std::endl;

    for (int i = 0; i < this->size; i++)
    {
        std::string first_name = this->contacts[i].first_name;
        std::string last_name = this->contacts[i].last_name;
        std::string nick_name = this->contacts[i].nick_name;
        std::cout << "|" << std::setw(10) << i + 1
                << "|" << std::setw(10) << first_name
                << "|" << std::setw(10) << last_name
                << "|" << std::setw(10) << nick_name
                << "|" << std::endl;
    }
}