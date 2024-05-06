#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
		bool guard_mode;

    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& rhs);
        ScavTrap& operator=(const ScavTrap& rhs);
        ~ScavTrap();

        void guardGate();
        void attack(std::string const& target);
};

#endif