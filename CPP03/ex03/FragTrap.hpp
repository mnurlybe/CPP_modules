#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name_input);
        FragTrap(const FragTrap &obj);
        ~FragTrap();

        FragTrap &operator=(const FragTrap &obj);

        void highFivesGuys(void);
};

#endif