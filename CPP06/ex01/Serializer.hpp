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

#endif