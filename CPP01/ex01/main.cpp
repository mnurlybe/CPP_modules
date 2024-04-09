/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:09:26 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/09 17:01:36 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N;
    std::string name;
    std::cout << "Enter amount: ";
    std::cin >> N;
    std::cout << "Enter name: ";
    std::cin >> name;
    
    if (N < 1)
    {
        std::cout << "no zombies to create!" << std::endl;
        return 0;    
    }
     
    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        horde[i].announce();

    std::cout << "destroying all zombies: ";
    delete[] horde;
    return 0;
}