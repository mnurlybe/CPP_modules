#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        std::string *ideas;
        
        Brain();
        Brain(const Brain &brain); // copy constructor
        Brain &operator=(const Brain &brain); // assignation operator overload
        ~Brain();

        std::string *setIdeas();
        std::string *getIdeas() const;
};

#endif