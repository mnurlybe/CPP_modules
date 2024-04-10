/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:05:42 by julienmoign       #+#    #+#             */
/*   Updated: 2024/04/10 16:20:50 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
    this->name = "Default";
    this->hit = FragTrap::hit;
    // std::cout << "ENERGY SHOULD BE 30, BUT IT IS " << ScavTrap::energy << std::endl;
    this->damage = FragTrap::damage;
    this->energy = ScavTrap::energy;
    std::cout << "[DIAMONDTRAP] Sub Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_input) : FragTrap(name_input + "_frag"), ScavTrap(name_input + "_scav")
{
    this->name = name_input;
    this->hit = FragTrap::hit;
    this->damage = FragTrap::damage;
    this->energy = ScavTrap::energy;
    std::cout << "[DIAMONDTRAP] Sub Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DIAMONDTRAP] Sub DiamondTrap Desctructor: " << name << " is terminated!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj.name + "_copy"), FragTrap(obj.name + "_copy"), ScavTrap(obj.name + "_copy")
{
    this->name = obj.name + "_copy";
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    std::cout << "[DIAMONDTRAP] Copy " << name << " is created." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    if (this == &obj)
        return *this;
    this->name = obj.name + "_assigned";
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    std::cout << "[DIAMONDTRAP] New " << name << " is assigned." << std::endl;
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "[DIAMONDTRAP] My name is " << this->name << ", and my ClapTrap name is " << this->ClapTrap::name << "!" << std::endl;
}
