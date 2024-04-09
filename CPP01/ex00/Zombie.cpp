#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "default";
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->name << " is dead" << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
