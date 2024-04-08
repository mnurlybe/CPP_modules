#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &AAnimal);
        AAnimal &operator=(const AAnimal &AAnimal);
        virtual ~AAnimal();

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif