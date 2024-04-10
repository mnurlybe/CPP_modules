/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:38 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 15:57:12 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//constructor
ClapTrap::ClapTrap()
{
    name = "Default";
    hit = 10;
    energy = 10;
    damage = 0;
    std::cout << "[CLAPTRAP] Parent Constructor: ClapTrap is initialized as " << name << std::endl;
}

//constructor with input
ClapTrap::ClapTrap(std::string name_input)
{
    name = name_input;
    hit = 10;
    energy = 10;
    damage = 0;
    std::cout << "[CLAPTRAP] Parent Constructor: ClapTrap is initialized as " << name << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap &obj)
{
    name = obj.name + "_copy";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "[CLAPTRAP] Copy " << name << " is created." << std::endl;
}

//assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& obj){
    name = obj.name + "_assigned";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "[CLAPTRAP] New " << name << " is assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "[CLAPTRAP] Parent Desctructor: " << name << " is terminated!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (hit < 1)
    {
        std::cout << "[CLAPTRAP] " << name << " is already destroyed!" << std::endl;
        return ;
    }
    if (energy > 0) {
        std::cout << "[CLAPTRAP] " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
        energy -= 1;
    }
    else{
        std::cout << "[CLAPTRAP] Not enough energy points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hit > 0){
        hit -= amount;
        std::cout << "[CLAPTRAP] " << name << " takes " << amount << " damage!" << std::endl;
        if (hit <= 0){
            std::cout << "[CLAPTRAP] "<< name << " has been destroyed!" << std::endl;
        }
    }
    else{
        std::cout << "[CLAPTRAP] " << name << " is already destroyed!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount){
    if (hit > 0){
        std::cout << "[CLAPTRAP] " << name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
        hit += amount;
        energy -= 1;
    }
    else {
        std::cout << "[CLAPTRAP] " << name << " Not enough hit points to repair!" << std::endl;
    }
}

void ClapTrap::get_data(void){
    std::cout << "[CLAPTRAP] " << name << "--> Hit points: " << hit << "; Energy points: " << energy << "; Damage: " << damage << std::endl;
}

std::string ClapTrap::getName(void) const{
    return name;
}

unsigned int ClapTrap::getHit(void) const{
    return hit;
}

unsigned int ClapTrap::getEnergy(void) const{
    return energy;
}

unsigned int ClapTrap::getDamage(void) const{
    return damage;
}
