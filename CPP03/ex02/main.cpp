/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/08 14:58:22 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    // Test 1: create a simple object
    FragTrap frag0;
    FragTrap frag1("FRAG1");
    FragTrap frag2(frag1);
    FragTrap frag3("FRAG3");
    frag3 = frag0;
    
    // Display initial data
    frag0.get_data();
    frag1.get_data();
    
    // Perform some actions
    frag0.attack("Enemy");
    frag1.attack("Enemy");
    frag0.takeDamage(10);
    frag1.takeDamage(50);
    frag0.beRepaired(10);
    frag1.beRepaired(1);
    frag1.highFivesGuys();
    frag0.highFivesGuys();

    frag1.get_data();
    frag1.beRepaired(10);
    frag1.get_data();
    
    return 0;
}
