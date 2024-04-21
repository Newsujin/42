#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType(); //함수 뒤에 const를 꼭 붙여야 하는지
        // const std::string getType(); //레퍼런스가 아닌 경우에는 왜 human의 이름이 바뀌는지
        void setType(std::string type);
};

#endif