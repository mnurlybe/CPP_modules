#ifndef Serializer_HPP
#define Serializer_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.h"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &source);
        Serializer& operator=(const Serializer &source);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

/* static methods (also called static member functions) are methods within a class 
that do not operate on any specific instance of the class. 
These methods belong to the class itself rather than to any individual object. */

#endif