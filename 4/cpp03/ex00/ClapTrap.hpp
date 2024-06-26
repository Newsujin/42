#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string  _name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;
		ClapTrap();
		
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap &operator=(const ClapTrap& rhs);
		~ClapTrap();

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string 	getName() const;
		unsigned int 	getHitPoints() const;
		unsigned int 	getEnergyPoints() const;
		unsigned int 	getAttackDamage() const;
};

#endif