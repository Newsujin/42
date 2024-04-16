#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
		std::cout << "Only positive value is allowed!\n";
		return (NULL);
	}

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        std::cout << i << " " << name << " is created" << std::endl;
    }
    return (horde);
}
