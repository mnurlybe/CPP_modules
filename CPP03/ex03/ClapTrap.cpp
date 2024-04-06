/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:38 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/06 19:50:32 by mnurlybe         ###   ########.fr       */
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
    std::cout << "Superclass Constructor: ClapTrap is initialized as " << name << std::endl;
}

//constructor with input
ClapTrap::ClapTrap(std::string name_input)
{
    name = name_input;
    hit = 10;
    energy = 10;
    damage = 0;
    std::cout << "Superclass Constructor: ClapTrap is initialized as " << name << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap &obj)
{
    name = obj.name + "_copy";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "ClapTrap Copy " << name << " is created." << std::endl;
}

//assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& obj){
    name = obj.name + "_assigned";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "New ClapTrap" << name << " is assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "Superclass Desctructor: " << name << " is terminated!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (hit < 1)
    {
        std::cout << name << " is already destroyed!" << std::endl;
        return ;
    }
    if (energy > 0) {
        std::cout << name << " attacks " << target << std::endl;
        energy -= 1;
    }
    else{
        std::cout << "Not enough energy points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hit > 0){
        hit -= amount;
        std::cout << name << " takes " << amount << " damage!" << std::endl;
        if (hit <= 0){
            std::cout << name << " has been destroyed!" << std::endl;
        }
    }
    else{
        std::cout << name << " is already destroyed!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount){
    if (hit > 0){
        std::cout << name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
        hit += amount;
        energy -= 1;
    }
    else {
        std::cout << "Not enough hit points to repair!" << std::endl;
    }
}

void ClapTrap::get_data(void){
    std::cout << name << "--> Hit points: " << hit << "; Energy points: " << energy << "; Damage: " << damage << std::endl;
}
