#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;

    public:
        void AddInfo();
        
        Contact::Contact(
        std::string first_name,
        std::string last_name,
        std::string nick_name,
        std::string phone_number,
        std::string darkest_secret
        )
        {
            this->first_name = first_name;
            this->last_name = last_name;
            this->nick_name = nick_name;
            this->phone_number = phone_number;
            this->darkest_secret = darkest_secret;
        }
};

class PhoneBook {
    public:
        Contact contacts[8];
        int     idx;
        int     size;
        void AddContact();
        void PrintInfo();
};

#endif