#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (&rhs == this)
		return (*this);
	_name = rhs._name;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap is dead" << std::endl;
}

void attack(const std::string& target) {

}

void takeDamage(unsigned int amount) {

}

void beRepaired(unsigned int amount) {

}
