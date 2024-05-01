#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("sujin");
	ClapTrap b(a);

	std::cout << a._attack_damage << std::endl;
	std::cout << b._attack_damage << std::endl;
}