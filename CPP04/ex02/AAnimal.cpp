#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal: constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    this->type = type;
    std::cout << "AAnimal type: constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal: destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &AAnimal)
{
    this->type = AAnimal.type;
    std::cout << "AAnimal: copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &AAnimal)
{
    if (this == &AAnimal)
        return *this;
    this->type = AAnimal.type;
    std::cout << "AAnimal: copy assignment operator called" << std::endl;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::makeSound() const
{
    std::cout << "No sound as AAnimal is not defined!" << std::endl;
}
