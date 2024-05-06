#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");
	ScavTrap c(a);
    std::cout << "----------------------------------------------------------" << std::endl;

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(5);
    std::cout << "----------------------------------------------------------" << std::endl;

    b.attack("C");
	c.takeDamage(20);
	c.beRepaired(5);
    std::cout << "----------------------------------------------------------" << std::endl;

    a.guardGate();
    a.guardGate();
    b.attack("A");
    std::cout << "----------------------------------------------------------" << std::endl;
    
    std::cout << a.getName() << "'s hit points: " << a.getHitPoints() << std::endl;
	std::cout << a.getName() << "'s energy points: " << a.getEnergyPoints() << std::endl;
	std::cout << a.getName() << "'s attack damage: " << a.getAttackDamage() << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

	std::cout << b.getName() << "'s hit points: " << b.getHitPoints() << std::endl;
	std::cout << b.getName() << "'s energy points: " << b.getEnergyPoints() << std::endl;
	std::cout << b.getName() << "'s attack damage: " << b.getAttackDamage() << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    std::cout << c.getName() << "'s hit points: " << c.getHitPoints() << std::endl;
	std::cout << c.getName() << "'s energy points: " << c.getEnergyPoints() << std::endl;
	std::cout << c.getName() << "'s attack damage: " << c.getAttackDamage() << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    return (0);
}