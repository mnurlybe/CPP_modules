
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

        // Overload operators
        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator*(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;

        // Increment operators
        Fixed &operator++(); // Preincrement
        Fixed operator++(int); // Postincrement
        Fixed &operator--(); // Predecrement
        Fixed operator--(int); // Postdecrement

        // Comparison operators
        bool operator>(const Fixed &obj) const; // Greater than
        bool operator<(const Fixed &obj) const; // Less than
        bool operator>=(const Fixed &obj) const; // Greater than or equal to
        bool operator<=(const Fixed &obj) const; // Less than or equal to
        bool operator==(const Fixed &obj) const; // Equal to
        bool operator!=(const Fixed &obj) const; // Not equal to

        // Min and Max
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif