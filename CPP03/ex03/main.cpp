/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/06 19:52:41 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap super("SUPER");
    // ScavTrap sub2("COPPIE");
    
    // sub2.get_data();
    // sub2.attack("Enemy");
    // sub2.beRepaired(0);
    // sub2.takeDamage(99);
    // sub2.get_data();

    // FragTrap frag0;
    FragTrap frag1("FRAG1");

    frag1.highFivesGuys();
    frag1.get_data();
    frag1.beRepaired(10);
    frag1.get_data();
    
    return 0;
}
