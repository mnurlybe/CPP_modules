/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 18:20:28 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{

    // write a message that says the initialization of the objects on std::cout
    std::cout << "=====================================================" << std::endl;
    std::cout << "Initialization, copy constructor, assignment operator" << std::endl;
    std::cout << "=====================================================" << std::endl;
    ScavTrap def;
    std::cout << std::endl;
    ScavTrap sub("ONE");
    std::cout << std::endl;
    ScavTrap sub1(sub);
    std::cout << std::endl;
    ScavTrap sub2("TWO");
    std::cout << std::endl;
    ScavTrap sub3("THREE");
    std::cout << std::endl;
    sub2 = sub3;
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                 Display initial data                " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    def.get_data();
    sub.get_data();
    sub1.get_data();
    sub2.get_data();
    sub3.get_data();
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                 Perform some actions                " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    //sub
    sub.attack("Enemy");
    sub.guardGate();
    sub.takeDamage(5);
    sub.beRepaired(0);
    sub.attack("Enemy");
    sub.beRepaired(42);
    std::cout << std::endl;
    std::cout << std::endl;
    //sub1
    sub1.attack("Enemy1");
    sub1.guardGate();
    sub1.takeDamage(0);
    sub1.beRepaired(0);
    sub1.takeDamage(50);
    sub1.beRepaired(50);
    std::cout << std::endl;
    std::cout << std::endl;
    //sub2
    sub2.guardGate();
    sub2.takeDamage(5);
    sub2.beRepaired(10);
    sub2.takeDamage(99);
    sub2.attack("Enemy2");
    std::cout << std::endl;
    std::cout << std::endl;
    //sub3
    sub3.takeDamage(46);
    sub3.beRepaired(0);
    sub3.takeDamage(99);
    sub3.attack("Enemy");
    sub3.beRepaired(10);
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                     Display data                    " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    def.get_data();
    sub.get_data();
    sub1.get_data();
    sub2.get_data();
    sub3.get_data();
    std::cout << std::endl;
    return 0;
}
