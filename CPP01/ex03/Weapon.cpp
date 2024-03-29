/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:32:07 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 16:49:35 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name){
    type = name;
}

Weapon::~Weapon(){
    ;
}

const std::string& Weapon::getType(void){
    return type;
}
void Weapon::setType(std::string new_type){
    type = new_type;
}
