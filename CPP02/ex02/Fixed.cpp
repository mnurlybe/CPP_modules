
#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value)
{
    _value = value << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _value = roundf(value * (1 << _fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        _value = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return out;
}


//================= Overload operators =================//

Fixed Fixed::operator+(const Fixed &obj) const
{
    return Fixed(toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return Fixed(toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return Fixed(toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    return Fixed(toFloat() / obj.toFloat());
}

//================= Increment operators =================//


/**
 * The pre-increment operator 
 * modifies the current object 
 * and returns a reference 
 * to the modified object.
*/
Fixed &Fixed::operator++()
{
    _value++;
    return *this;
}

/**
 * The post-increment operator 
 * returns a copy of the original 
 * object before modification and 
 * then increments the current object's value.
*/
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

//================= Comparison operators =================//

bool Fixed::operator>(const Fixed &obj) const
{
    return _value > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
    return _value < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return _value >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return _value <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
    return _value == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return _value != obj.getRawBits();
}

//================= Min and Max =================//

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}
