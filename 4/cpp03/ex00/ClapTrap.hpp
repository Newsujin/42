#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string	_name;
		int			_hit_points = 10;
		int			_energy_points = 10;
		int			_attack_damage = 0;
		ClapTrap();
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap &operator=(const ClapTrap& rhs);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::ostream&	operator<<(std::ostream& ostream, const ClapTrap& rhs);

#endif