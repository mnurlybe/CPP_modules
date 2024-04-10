#include "Brain.hpp"

Brain::Brain()
{
    this->ideas = setIdeas();
    std::cout << "Brain: constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = brain.ideas[i] + "_copy_";
    }
    std::cout << "Brain: copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    if (this == &brain)
        return *this;

    delete[] this->ideas;
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i] + "_assigned_";
    std::cout << "Brain: copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    delete[] this->ideas;
    std::cout << "Brain: destructor called" << std::endl;
}

std::string *Brain::setIdeas()
{
    std::string *ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = "Idea ";
    }
    return ideas;
}

std::string *Brain::getIdeas() const
{
    return this->ideas;
}