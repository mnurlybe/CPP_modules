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

void Zombie::setName(std::string name, int i){
    this->name = name;
    this->id = i;
}
void Zombie::announce(void)
{
    std::cout << this->name << this->id << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
