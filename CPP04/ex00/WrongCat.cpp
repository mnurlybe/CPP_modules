#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "[WRONGCAT] constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WRONGCAT] destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal()
{
    *this = wrongCat;
    std::cout << "[WRONGCAT] copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    if (this == &wrongCat)
        return *this;
    this->_type = wrongCat._type;
    std::cout << "[WRONGCAT] copy assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WOEM WOEM!" << std::endl;
}