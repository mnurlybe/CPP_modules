/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:57:04 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/06 20:15:45 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//constructor
DiamondTrap::DiamondTrap()
{
    hit = FragTrap::hit;
    energy = ScavTrap::energy;
    damage = FragTrap::damage;
    std::cout << "Constructor: DiamondTrap is initialized as " << name << std::endl;
}

//constructor with input
DiamondTrap::DiamondTrap(std::string name_input) : ClapTrap(name_input + "_clap_name")
{
    hit = ;
    energy = 100;
    damage = 100;
    std::cout << "Subclass Constructor: DiamondTrap is initialized as " << name << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Subclass DiamondTrap Desctructor: " << name << " is terminated!" << std::endl;
}

//copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
    name = obj.name + "_copy";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "Sub: DiamondTrap Copy " << name << " is created." << std::endl;
}

//assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj){
    name = obj.name + "_assigned";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "Sub: New DiamondTrap" << name << " is assigned." << std::endl;
    return *this;
}