#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
	guard_mode = false;
    std::cout << "ScavTrap " << _name << " is born" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
	guard_mode = rhs.guard_mode;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if (&rhs == this)
		return (*this);
	_name = rhs._name;
	_hit_points = rhs._hit_points;
	_energy_points = rhs._energy_points;
	_attack_damage = rhs._attack_damage;
	std::cout << "ScavTrap " << _name << " copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
    if (!_hit_points || !_energy_points)
		std::cout << "\033[31mScavTrap " << _name << " has no power to attack ...\033[0m" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
				<< _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
}

void	ScavTrap::guardGate()
{
	if (!guard_mode)
	{
		guard_mode = true;
		std::cout << "\033[33mScavTrap " << _name << " is now in guard gate mode.\033[0m" << std::endl;
	}
	else
		std::cout << "\033[33mScavTrap " << _name << " is already in guard gate mode.\033[0m" << std::endl;
}