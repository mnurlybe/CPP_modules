/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:15:51 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/23 20:06:44 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (command != "EXIT")
    {
        std::cout << "Commands to use: ADD, SEARCH and EXIT." << std::endl;
        std::cin >> command;
        if (command == "ADD")
        {
            std::cout << "[You entered: ADD]" << std::endl;
            phonebook.add();
        }
        else if (command == "SEARCH")
        {
            std::cout << "You entered: SEARCH" << std::endl;
            phonebook.search();
        }
        else if (command != "EXIT")
            std::cout << "You entered invalid command, please try again." << std::endl;
    }
    return 0;
}

/**
 * Plan:
 * 
 * 1. Handle Add:
 *      a. handle empty fields; 
 * 2. Handle Search;
*/