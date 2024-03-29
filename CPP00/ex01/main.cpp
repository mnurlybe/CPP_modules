/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:15:51 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 15:26:12 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (command != "EXIT" && std::cin.eof() == 0)
    {
        std::cout << "Commands to use: ADD, SEARCH and EXIT." << std::endl;
        getline(std::cin, command);
        if (command.compare("ADD") == 0)
        {
            std::cout << "[You entered: ADD]" << std::endl;
            phonebook.add();
        }
        else if (command.compare("SEARCH") == 0)
        {
            std::cout << "You entered: SEARCH" << std::endl;
            phonebook.search();
        }
        else if (command.compare("EXIT") != 0)
            std::cout << "You entered invalid command, please try again." << std::endl;
    }
    return 0;
}
