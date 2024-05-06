#include "ClapTrap.hpp"

int	main()
{
	ClapTrap amateur("amateur");
	ClapTrap master("master");
    std::cout << "-----------------------------------------------------------" << std::endl;

	amateur.attack("master");
	master.takeDamage(5);
	master.beRepaired(4);
    std::cout << "-----------------------------------------------------------" << std::endl;

	master.attack("amateur");
	amateur.takeDamage(100);
	amateur.beRepaired(10);
    std::cout << "-----------------------------------------------------------" << std::endl;

	std::cout << master.getName() << "'s hit points: " << master.getHitPoints() << std::endl;
	std::cout << master.getName() << "'s energy points: " << master.getEnergyPoints() << std::endl;
	std::cout << master.getName() << "'s attack damage: " << master.getAttackDamage() << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

	std::cout << amateur.getName() << "'s hit points: " << amateur.getHitPoints() << std::endl;
	std::cout << amateur.getName() << "'s energy points: " << amateur.getEnergyPoints() << std::endl;
	std::cout << amateur.getName() << "'s attack damage: " << amateur.getAttackDamage() << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

	return (0);
}