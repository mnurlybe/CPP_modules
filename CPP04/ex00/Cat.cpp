#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[CAT]: constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[CAT]: destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat.type)
{
    *this = cat;
    std::cout << "[CAT]: copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this == &cat)
        return *this;
    this->type = cat.type;
    std::cout << "[CAT]: copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}