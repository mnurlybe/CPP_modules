/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:42:40 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 15:58:10 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//constructor
FragTrap::FragTrap() : ClapTrap()
{
    hit = 100;
    energy = 100;
    damage = 30;
    std::cout << "[FRAGTRAP] Sub Constructor: FragTrap is initialized as " << name << std::endl;
}

//constructor with input
FragTrap::FragTrap(std::string name_input) : ClapTrap(name_input)
{
    hit = 100;
    energy = 100;
    damage = 30;
    std::cout << "[FRAGTRAP] Sub Constructor: FragTrap is initialized as " << name << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "[FRAGTRAP] Sub Desctructor: " << name << " is terminated!" << std::endl;
}

//copy constructor
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    name = obj.name + "_copy";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "[FRAGTRAP] Copy " << name << " is created." << std::endl;
}

//assignment operator
FragTrap& FragTrap::operator=(const FragTrap& obj){
    if (this == &obj)
        return *this;
    name = obj.name + "_assigned";
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    std::cout << "[FRAGTRAP] New " << name << " is assigned." << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void){
    std::cout << "[FRAGTRAP] " << name << " High Fives Guys!" << std::endl;
}