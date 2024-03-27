#include "contact.hpp"

void    Contact::AddInfo(void)
{
    std::cout << "First Name: ";
    std::cin >> this->first_name;
    std::cout << "Last Name: ";
    std::cin >> this->last_name;
    std::cout << "Nick Name: ";
    std::cin >> this->nick_name;
    std::cout << "Phone Number: ";
    std::cin >> this->phone_number;
    std::cout << "Darkest Secret: ";
    std::cin >> this->darkest_secret;
    std::cout << "Saved successfully";
}

std::string Contact::getShortStr(std::string str)
{
    if (static_cast<int>(str.size()) > 10)
        return (str.substr(0, 9) + ".");
}