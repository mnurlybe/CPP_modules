/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:55:37 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/09 17:35:33 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
    ;
}

Harl::~Harl(){
    std::cout << "destructor.. exiting the program." << std::endl;
}

void Harl::debug(void){
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;    
}

void Harl::invalid(void){
    std::cout << "[SMTH ELSE] Probably complaining about insignificant problems" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    fptr action[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::invalid};
    int i = 0;
    while(i < 4 && level.compare(levels[i])){
            i++;
    }
    (this->*(action[i]))();
}