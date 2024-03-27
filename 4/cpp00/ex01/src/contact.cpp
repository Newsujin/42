#include "contact.hpp"

std::string Contact::getFirstName() const {return this->first_name;}
std::string Contact::getLastName() const {return this->last_name;}
std::string Contact::getNickName() const {return this->nick_name;}
std::string Contact::getPhoneNumber() const {return this->phone_number;}
std::string Contact::getDarkestSecret() const {return this->darkest_secret;}

void Contact::setFirstName()
{
    while (true) {
        std::cout << "First Name: ";
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            exit(0);
        if (first_name.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setLastName()
{
    while (true) {
        std::cout << "Last Name: ";
        std::getline(std::cin, last_name);
        if (std::cin.eof())
            exit(0);
        if (last_name.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setNickName()
{
    while (true) {
        std::cout << "Nick Name: ";
        std::getline(std::cin, nick_name);
        if (std::cin.eof())
            exit(0);
        if (nick_name.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setPhoneNumber()
{
    while (true) {
        std::cout << "Phone Number: ";
        std::getline(std::cin, phone_number);
        if (std::cin.eof())
            exit(0);
        if (phone_number.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setDarkestSecret()
{
    while (true) {
        std::cout << "Darkest Secret: ";
        std::getline(std::cin, darkest_secret);
        if (std::cin.eof())
            exit(0);
        if (darkest_secret.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}
