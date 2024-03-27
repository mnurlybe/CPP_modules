#include "Zombie.hpp"

void ramdomChump( std::string name )
{
    Zombie z;
    z.setName(name);
    z.announce();
}