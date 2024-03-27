#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        Contact(
        std::string _first_name,
        std::string _last_name,
        std::string _nick_name,
        std::string _phone_number,
        std::string _darkest_secret
        );
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
        void setFirstName();
        void setLastName();
        void setNickName();
        void setPhoneNumber();
        void setDarkestSecret();
};

#endif