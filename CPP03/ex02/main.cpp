/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 15:49:15 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=====================================================" << std::endl;
    std::cout << "Initialization, copy consturctor, assignment operator" << std::endl;
    std::cout << "=====================================================" << std::endl;
    FragTrap frag0;
    FragTrap frag1("FRAG1");
    FragTrap frag2(frag1);
    FragTrap frag3("FRAG3");
    FragTrap frag4("FRAG4");
    frag4 = frag3;
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                 Display initial data                " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    frag0.get_data();
    frag1.get_data();
    frag2.get_data();
    frag3.get_data();
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                 Perform some actions                " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    //frag0
    frag0.attack("Enemy");
    frag0.highFivesGuys();
    frag0.takeDamage(5);
    frag0.beRepaired(0);
    frag0.attack("Enemy");
    frag0.beRepaired(42);
    std::cout << std::endl;
    //frag1
    frag1.attack("Enemy1");
    frag1.highFivesGuys();
    frag1.takeDamage(0);
    frag1.beRepaired(0);
    frag1.takeDamage(50);
    frag1.beRepaired(50);
    std::cout << std::endl;
    //frag2
    frag2.highFivesGuys();
    frag2.takeDamage(5);
    frag2.beRepaired(10);
    frag2.takeDamage(99);
    frag2.attack("Enemy2");
    std::cout << std::endl;
    std::cout << std::endl;
    //frag3
    frag3.takeDamage(46);
    frag3.beRepaired(0);
    frag3.takeDamage(99);
    frag3.attack("Enemy");
    frag3.beRepaired(10);
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                     Display data                    " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    frag0.get_data();
    frag1.get_data();
    frag2.get_data();
    frag3.get_data();
    std::cout << std::endl;
    
    return 0;
}
