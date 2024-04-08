/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/08 15:38:07 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    // Test 1: create a simple object
    // DiamondTrap diam;
    DiamondTrap diam1("DIAM1");
    // DiamondTrap diam2(diam1);
    // DiamondTrap diam3("DIAM3");
    // diam3 = diam;

    diam1.whoAmI();
    
    // Display initial data
    // diam.get_data();
    diam1.get_data();
    diam1.takeDamage(50);
    diam1.get_data();
    
    return 0;
}
