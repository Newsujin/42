#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void f()
// {
//     system("leaks a.out");
// }

int main()
{
    // atexit(f);
	
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    std::cout << wa->getType() << " " << std::endl;
    wa->makeSound();
    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wa;
    delete wc;

    return 0;
}