#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "default";
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->name << " is dead" << std::endl;
}
