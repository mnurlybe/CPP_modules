#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name_input);
        ScavTrap(const ScavTrap &obj);
        ~ScavTrap();

        ScavTrap &operator=(const ScavTrap &obj);
        
        void attack(const std::string& target);
        void guardGate();
        void get_data(void);
};

#endif