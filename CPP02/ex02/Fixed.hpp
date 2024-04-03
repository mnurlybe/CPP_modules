
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed(); // Default constructor
        Fixed(const Fixed &fixed); // Copy constructor
        ~Fixed(); // Destructor
        Fixed &operator=(const Fixed &fixed); // Assignation operator
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif