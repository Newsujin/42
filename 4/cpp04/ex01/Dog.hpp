#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog &rhs);
        Dog& operator=(const Dog &rhs);
        ~Dog();

        void makeSound() const;
        std::string getDogIdea(int idx) const;
        void setDogIdea(int idx, std::string idea);
};

#endif