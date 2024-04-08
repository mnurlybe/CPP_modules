#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat: destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    this->brain = NULL;
    this->type = cat.type;
    if (cat.brain)
        this->brain = new Brain(*cat.brain);
    std::cout << "Cat: copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this == &cat)
        return *this;
    this->type = cat.type;
    delete this->brain;
    this->brain = new Brain(*cat.brain);
    std::cout << "Cat: copy assignement operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}

void Cat::print_ideas() const
{
    std::string *ideas = this->brain->getIdeas();
    for (int i = 0; i < 100; i++)
    {
        std::cout << ideas[i] << std::endl;
    }
}

void Cat::print_address() const
{
    std::cout << "Cat address: " << this << std::endl;
    std::cout << "Cat's Brain address: " << this->brain << std::endl;
}