
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed(); // Default constructor
        Fixed(const Fixed &fixed); // Copy constructor
        Fixed(int const value); // Int constructor
        Fixed(float const value); // Float constructor
        ~Fixed(); // Destructor
        
        Fixed &operator=(const Fixed &fixed); // Assignation operator
        
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const; //converts the fixed point value to a floating point value
        int toInt(void) const; //converts the fixed point value to an integer value
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif