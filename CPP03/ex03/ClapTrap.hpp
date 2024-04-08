/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:44 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/08 15:31:20 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap{
    protected:
        std::string name;
        unsigned int hit;
        unsigned int energy;
        unsigned int damage;

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

        std::string getName(void) const;                //Getter
        unsigned int getHit(void) const;                //Getter
        unsigned int getEnergy(void) const;             //Getter
        unsigned int getDamage(void) const;             //Getter
};

#endif
