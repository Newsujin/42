#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal	*animal = new Animal();
	
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
    
    return 0;
}