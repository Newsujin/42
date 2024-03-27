#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int     idx;
        int     size;
        
    public:
        PhoneBook();
        void AddContact();
        void PrintInfo();
        void PrintContact(int index);
        std::string getShortStr(std::string str);
};

#endif