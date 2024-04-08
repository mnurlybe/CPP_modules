/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/08 15:34:45 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{

    // // Test 1: create a simple object
    // ClapTrap super("SUPER");
    // ScavTrap sub("SUB");
    
    // // Display initial data
    // super.get_data();
    // sub.get_data();
    
    // // Perform some actions
    // sub.attack("Enemy");
    // sub.guardGate();
    // sub.takeDamage(5);
    // sub.get_data();
    // sub.beRepaired(0);
    // sub.takeDamage(99);

    // super.get_data();
    // sub.get_data();
    
    // // Test 2: copy constructor and assignment operator
    // ScavTrap sub;
    // ScavTrap sub1(sub);
    ScavTrap sub2("TWO");
    ScavTrap sub3("THREE");
    sub2 = sub3;

    // // Display initial data
    // sub.get_data();
    // sub1.get_data();
    // sub2.get_data();
    // sub3.get_data();

    // // Perform some actions
    // sub.attack("Enemy");
    // sub2.guardGate();
    sub3.takeDamage(46);
    sub3.get_data();
    // sub3.get_data();
    // sub3.beRepaired(0);
    // sub3.takeDamage(99);
    // sub1.beRepaired(10);
    // sub2.attack("Enemy");
    // sub2.beRepaired(10);
    
    // sub.get_data();
    // sub1.get_data();
    // sub2.get_data();
    // sub3.get_data();
    
    return 0;
}
