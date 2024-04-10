#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name_input);
        ScavTrap(const ScavTrap &obj);
        ~ScavTrap();

        ScavTrap &operator=(const ScavTrap &obj);
        
        void attack(const std::string& target);
        void guardGate();
};

#endif