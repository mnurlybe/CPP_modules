/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/06 18:05:32 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Uno");
    ClapTrap b(a);
    ClapTrap c;
    c = a;
    
    a.attack("Enemy1");
    a.takeDamage(10);
    a.beRepaired(3);
    a.attack("Enemy2");
    a.attack("Enemy3");
    a.attack("Enemy4");
    a.get_data();
    b.get_data();
    
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