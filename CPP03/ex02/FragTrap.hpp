#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name_input);
        FragTrap(const FragTrap &obj);
        ~FragTrap();

        FragTrap &operator=(const FragTrap &obj);

        void highFivesGuys(void);
        void attack(const std::string& target);
        void get_data(void);
};

#endif