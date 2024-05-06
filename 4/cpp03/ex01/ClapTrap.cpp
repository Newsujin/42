#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _hit_points(10)
	, _energy_points(10)
	, _attack_damage(0)
{
	std::cout << "ClapTrap " << _name << " is born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << "ClapTrap " << rhs._name << " copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (&rhs == this)
		return (*this);
	_name = rhs._name;
	_hit_points = rhs._hit_points;
	_energy_points = rhs._energy_points;
	_attack_damage = rhs._attack_damage;
	std::cout << "ClapTrap " << _name << " copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!_hit_points || !_energy_points)
		std::cout << "\033[31mClapTrap " << _name << " has no power to attack ...\033[0m" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
				<< _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hit_points)
		std::cout << "\033[31mClapTrap " << _name << " has no hp to get the damage ...\033[0m" << std::endl;
	else
	{
		if (amount > _hit_points)
			_hit_points = 0;
		else
			_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " has taken " << amount << " damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hit_points || !_energy_points)
		std::cout << "\033[31mClapTrap " << _name << " has no power to be repaired ...\033[0m" << std::endl;
	else
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << "ClapTrap " << _name << " repaired itself by " << amount
				<< ", It has now " << _hit_points << " hit points" << std::endl;
	}
}

std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (_energy_points);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attack_damage);
}