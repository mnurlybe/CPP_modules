/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:28:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/10 18:20:38 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("ONE");
    ClapTrap b(a);
    ClapTrap c;
    c = a;
    std::cout << std::endl;
    a.attack("Enemy1");
    std::cout << std::endl;
    a.takeDamage(10);
    std::cout << std::endl;
    a.beRepaired(3);
    std::cout << std::endl;
    a.attack("Enemy2");
    std::cout << std::endl;
    a.attack("Enemy3");
    std::cout << std::endl;
    a.attack("Enemy4");
    std::cout << std::endl;
    a.get_data();
    std::cout << std::endl;
    b.get_data();
    std::cout << std::endl;
    b.takeDamage(7);
    std::cout << std::endl;
    b.attack("Enemy5");
    std::cout << std::endl;
    b.beRepaired(5);
    std::cout << std::endl;
    b.get_data();
    std::cout << std::endl;
    
    return 0;
}
