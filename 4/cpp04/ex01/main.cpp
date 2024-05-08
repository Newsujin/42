#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void f()
{
    system("leaks a.out");
}
int main()
{
    atexit(f);
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // j->makeSound();
    // i->makeSound();
    // delete j;
    // delete i;
	// std::cout << "-----------------------------------" << std::endl;

    Animal  *ani[4];
    for(int i = 0; i < 4; i++)
    {
        if (i % 2)
            ani[i] = new Cat();
        else
            ani[i] = new Dog();
    }
    for(int i = 0; i < 4; i++)
        ani[i]->makeSound();
    for(int i = 0; i < 4; i++)
        delete ani[i];
	std::cout << "-----------------------------------" << std::endl;
    
	Dog *puppy = new Dog();
	Cat *kitty = new Cat();
	std::cout << "[puppy] " << puppy->getDogIdea(10) << std::endl;
	std::cout << "[kitty] " <<  kitty->getCatIdea(10) << std::endl;

    puppy->setDogIdea(10, "I'd like to play!");
    kitty->setCatIdea(10, "I'd like to take a nap ...");
    std::cout << "[puppy] " <<  puppy->getDogIdea(10) << std::endl;
	std::cout << "[kitty] " <<  kitty->getCatIdea(10) << std::endl;
	std::cout << "-----------------------------------" << std::endl;

    Dog *som = new Dog();
    Cat *gamja = new Cat();
    *som = *puppy;
    *gamja = *kitty;
    som->setDogIdea(10, "I love my family *^^*");
    gamja->setCatIdea(10, "I'm hungry ,,,");
	std::cout << "[som] " <<  som->getDogIdea(10) << std::endl;
	std::cout << "[gamja] " <<  gamja->getCatIdea(10) << std::endl;
	std::cout << "[puppy] " <<   puppy->getDogIdea(10) << std::endl;
	std::cout << "[kitty] " <<   kitty->getCatIdea(10) << std::endl;

    delete puppy;
    delete kitty;
    delete som;
    delete gamja;
    
    return 0;
}