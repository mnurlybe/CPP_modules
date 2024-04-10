#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "[DOG]: constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[DOG]: destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog.type)
{
    *this = dog;
    std::cout << "[DOG]: copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this == &dog)
        return *this;
    this->type = dog.type;
    std::cout << "[DOG]: copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}