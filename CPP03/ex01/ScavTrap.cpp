/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:21:08 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 15:33:56 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//constructor
ScavTrap::ScavTrap() : ClapTrap()
{
    hit = 100;
    energy = 50;
    damage = 20;
    std::cout << "[SCAVTRAP] Sub Constructor: ScavTrap is initialized as " << name << std::endl;
}

//constructor with input
ScavTrap::ScavTrap(std::string name_input) : ClapTrap(name_input)
{
    hit = 100;
    energy = 50;
    damage = 20;
    std::cout << "[SCAVTRAP] Sub Constructor: ScavTrap is initialized as " << name << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "[SCAVTRAP] Sub Desctructor: " << name << " is terminated!" << std::endl;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj)
{
    name = obj.name + "_copy";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "[SCAVTRAP] Copy " << name << " is created." << std::endl;
}

//assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& obj){
    
    if (this == &obj)
        return *this;
    name = obj.name + "_assigned";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "[SCAVTRAP] New " << name << " is assigned." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target){
    if (hit < 1)
    {
        std::cout << "[SCAVTRAP] " << name << " is already destroyed!" << std::endl;
        return ;
    }
    if (energy > 0) {
        std::cout << "[SCAVTRAP] " << name << " attacks " << target << std::endl;
        energy -= 1;
    }
    else{
        std::cout << "[SCAVTRAP] " << name << " doesn't have enough energy points to attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "[SCAVTRAP] " << name << " entered Gate keeper mode! "<< std::endl;
}

void ScavTrap::get_data(void){
    std::cout << "[SCAVTRAP] " << name << "--> Hit points: " << hit << "; Energy points: " << energy << "; Damage: " << damage << std::endl;
}



