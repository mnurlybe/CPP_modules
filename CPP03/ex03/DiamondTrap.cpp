/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:05:42 by julienmoign       #+#    #+#             */
/*   Updated: 2024/04/10 18:19:38 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->name = "name";
    this->ClapTrap::name = this->name + "_clap_name";
    this->hit = FragTrap::hit;
    this->damage = FragTrap::damage;
    ScavTrap::energy = 50;
    this->energy = ScavTrap::energy;
    std::cout << "[DIAMONDTRAP] Sub Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_input) : ScavTrap(name_input + "_scav"), FragTrap(name_input + "_frag")
{
    this->name = name_input;
    this->ClapTrap::name = this->name + "_clap_name";
    this->hit = FragTrap::hit;
    this->damage = FragTrap::damage;
    ScavTrap::energy = 50;
    this->energy = ScavTrap::energy;
    std::cout << "[DIAMONDTRAP] Sub Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DIAMONDTRAP] Sub DiamondTrap Desctructor: " << name << " is terminated!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj.name + "_copy"), ScavTrap(obj.name + "_copy"), FragTrap(obj.name + "_copy")
{
    this->name = obj.name + "_copy";
    this->ClapTrap::name = this->name + "_clap_name";
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
