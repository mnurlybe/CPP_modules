#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat.type)
{
    *this = cat;
    std::cout << "Cat: copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this == &cat)
        return *this;
    this->type = cat.type;
    std::cout << "Cat: copy assignement operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}