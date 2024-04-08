#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog: constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog: destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{   
    this->brain = NULL;
    this->type = dog.type;
    if (dog.brain)
        this->brain = new Brain(*dog.brain);
    std::cout << "Dog: copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this == &dog)
        return *this;
    this->type = dog.type;
    delete this->brain;
    this->brain = new Brain(*dog.brain);
    std::cout << "Dog: copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::print_ideas() const
{
    std::string *ideas = this->brain->getIdeas();
    for (int i = 0; i < 100; i++)
    {
        std::cout << ideas[i] << std::endl;
    }
}

void Dog::print_address() const
{
    std::cout << "Dog address: " << this << std::endl;
    std::cout << "Dog's Brain address: " << this->brain << std::endl;
}