/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:21:08 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/06 19:43:47 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//constructor
ScavTrap::ScavTrap() : ClapTrap()
{
    hit = 100;
    energy = 50;
    damage = 20;
    std::cout << "Constructor: ClapTrap is initialized as " << name << std::endl;
}

//constructor with input
ScavTrap::ScavTrap(std::string name_input) : ClapTrap(name_input)
{
    hit = 100;
    energy = 50;
    damage = 20;
    std::cout << "Subclass Constructor: ScavTrap is initialized as " << name << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Subclass ScavTrap Desctructor: " << name << " is terminated!" << std::endl;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap &obj)
{
    name = obj.name + "_copy";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "Sub: ScavTrap Copy " << name << " is created." << std::endl;
}

//assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& obj){
    name = obj.name + "_assigned";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "Sub: New ScavTrap" << name << " is assigned." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target){
    if (hit < 1)
    {
        std::cout << "Sub: " << name << " is already destroyed!" << std::endl;
        return ;
    }
    if (energy > 0) {
        std::cout << "Sub: " << name << " attacks " << target << std::endl;
        energy -= 1;
    }
    else{
        std::cout << "Sub: " << name << " doesn't have enough energy points to attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap " << name << " entered Gate keeper mode! "<< std::endl;
}

