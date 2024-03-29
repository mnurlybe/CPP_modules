#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "default";
    id = 0;
}

Zombie::~Zombie( void )
{
    std::cout << "\nZombie " << this->name << this->id << " is dead";
}
