#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal: default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    _type = wrongAnimal.getType();
    std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    if (this == &wrongAnimal)
        return *this;
    this->_type = wrongAnimal.getType();
    std::cout << "WrongAnimal: copy assignement operator called" << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "No sound as WrongAnimal is not defined!" << std::endl;
}