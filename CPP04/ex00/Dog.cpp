#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog.type)
{
    *this = dog;
    std::cout << "Dog: copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this == &dog)
        return *this;
    this->type = dog.type;
    std::cout << "Dog: copy assignement operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}