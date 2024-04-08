/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:44 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/08 14:19:31 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hit;
        int energy;
        int damage;

    public:
        ClapTrap();                                 //Default constructor
        ClapTrap(std::string name_input);           //Default constructor with input
        ClapTrap(const ClapTrap &obj);              //Copy constructor
        ~ClapTrap();                                //Destructor
        
        ClapTrap &operator=(const ClapTrap &obj);   //Assignment operator
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void get_data(void);
};

#endif
