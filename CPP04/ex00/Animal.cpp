#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal: constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: destructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
    std::cout << "Animal: copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    if (this == &animal)
        return *this;
    this->type = animal.type;
    std::cout << "Animal: copy assignement operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "No sound as Animal is not defined!" << std::endl;
}
