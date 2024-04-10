#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat: constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal()
{
    *this = wrongCat;
    std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    if (this == &wrongCat)
        return *this;
    this->_type = wrongCat._type;
    std::cout << "WrongCat: copy assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Woem Weom!" << std::endl;
}