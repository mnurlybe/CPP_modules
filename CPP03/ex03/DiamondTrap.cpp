/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:05:42 by julienmoign       #+#    #+#             */
/*   Updated: 2024/04/08 15:33:34 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    this->name = "Default";
    this->hit = this->FragTrap::hit;
    this->energy = this->ScavTrap::energy;
    this->damage = this->FragTrap::damage;
    std::cout << "Subclass Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_input) : ClapTrap(name_input + "_clap_name"), ScavTrap(name_input + "_scav"), FragTrap(name_input + "_frag")
{
    this->name = name_input;
    this->hit = this->FragTrap::hit;
    this->energy = this->ScavTrap::energy;
    this->damage = this->FragTrap::damage;
    std::cout << "Subclass Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Subclass DiamondTrap Desctructor: " << name << " is terminated!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj.name + "_clap_name"), ScavTrap(obj.name + "_scav"), FragTrap(obj.name + "_frag")
{
    this->name = obj.name + "_copy";
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    std::cout << "Sub: DiamondTrap Copy " << name << " is created." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    if (this == &obj)
        return *this;
    this->name = obj.name + "_assigned";
    this->hit = obj.hit;
    this->energy = obj.energy;
    this->damage = obj.damage;
    std::cout << "Sub: New DiamondTrap" << name << " is assigned." << std::endl;
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap: My name is " << this->name << " is " << this->ClapTrap::name << std::endl;
}
