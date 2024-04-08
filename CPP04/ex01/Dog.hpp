#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{ 
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);

        void makeSound() const;
        void print_ideas() const;
        void print_address() const;
};

#endif