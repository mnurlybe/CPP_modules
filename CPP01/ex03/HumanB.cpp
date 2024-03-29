/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:32:38 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 17:11:39 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name_input) : name(name_input) {  
    weapon = NULL;
}

HumanB::~HumanB(){
    ;
}

void HumanB::attack(){
    if (weapon == NULL)
        std::cout << name << "doesn't have a weapon" << std::endl;
    else
        std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
    weapon = &w;
}