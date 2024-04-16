#include "Zombie.hpp"

int main(void)
{
    int N = 3;

    Zombie* horde = zombieHorde(N, "zombie");
    if (!horde)
        return (0);
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete []horde;
    return (0);
}
