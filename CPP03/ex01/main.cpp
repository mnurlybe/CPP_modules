/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/06 19:36:32 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap super("SUPER");
    // ScavTrap sub;
    // ScavTrap sub1(sub);
    ScavTrap sub2("COPPIE");
    // sub2 = sub;
    
    // super.get_data();
    // sub.takeDamage(5);
    // super.get_data();
    // sub1.get_data();
    // sub.get_data();
    sub2.get_data();
    sub2.attack("Enemy");
    sub2.beRepaired(0);
    sub2.takeDamage(99);
    sub2.get_data();
    return 0;
}

// // Create ClapTrap objects
// ClapTrap claptrap1("Clappy1");
// ClapTrap claptrap2("Clappy2");

// // Display initial data
// claptrap1.get_data();
// claptrap2.get_data();

// // Perform some actions
// claptrap1.attack("Enemy");
// claptrap2.takeDamage(3);
// claptrap1.beRepaired(2);
// claptrap2.attack("Enemy");

// // Display updated data
// claptrap1.get_data();
// claptrap2.get_data();

// // Test copy constructor
// ClapTrap claptrap3(claptrap1);
// claptrap3.get_data();

// // Test assignment operator
// claptrap2 = claptrap3;
// claptrap2.get_data();