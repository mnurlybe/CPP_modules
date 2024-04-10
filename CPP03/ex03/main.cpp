/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 18:20:18 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "=====================================================" << std::endl;
    std::cout << "Initialization, copy constructor, assignment operator" << std::endl;
    std::cout << "=====================================================" << std::endl;
    DiamondTrap Diamond0;
    DiamondTrap Diamond1("Diamond1");
    DiamondTrap Diamond2(Diamond1);
    DiamondTrap Diamond3("Diamond3");
    DiamondTrap Diamond4("Diamond4");
    Diamond4 = Diamond3;
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                 Display initial data                " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    Diamond0.get_data();
    Diamond1.get_data();
    Diamond2.get_data();
    Diamond3.get_data();
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                 Perform some actions                " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    //Diamond0
    Diamond0.attack("Enemy");
    Diamond0.whoAmI();
    Diamond0.takeDamage(5);
    Diamond0.beRepaired(0);
    Diamond0.attack("Enemy");
    Diamond0.beRepaired(42);
    std::cout << std::endl;
    //Diamond1
    Diamond1.attack("Enemy1");
    Diamond1.whoAmI();
    Diamond1.takeDamage(0);
    Diamond1.beRepaired(0);
    Diamond1.takeDamage(50);
    Diamond1.beRepaired(50);
    std::cout << std::endl;
    //Diamond2
    Diamond2.whoAmI();
    Diamond2.takeDamage(5);
    Diamond2.beRepaired(10);
    Diamond2.takeDamage(99);
    Diamond2.attack("Enemy2");
    std::cout << std::endl;
    std::cout << std::endl;
    //Diamond3
    Diamond3.takeDamage(46);
    Diamond3.beRepaired(0);
    Diamond3.takeDamage(99);
    Diamond3.attack("Enemy");
    Diamond3.beRepaired(10);
    std::cout << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "                     Display data                    " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << std::endl;
    Diamond0.get_data();
    Diamond1.get_data();
    Diamond2.get_data();
    Diamond3.get_data();
    std::cout << std::endl;
    
    return 0;
}
