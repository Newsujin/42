#include <iostream>

int main(int ac, char *av[])
{

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str(av[i]);
            for (int j = 0; str[j]; j++)
                std::cout << static_cast<char>(std::toupper(str[j]));
        }
    }
    std::cout << std::endl;
    return (0);
}