/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:01:29 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/23 20:25:48 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::add()
{
    if (index > 7)
        index = 7;
    Contacts[index].fill_contact(index);
    index++;
}

void    PhoneBook::search()
{
    if (index == 0)
    {
        std::cout << "Phonebook is empty, there is nothing to display" << std::endl;
        return ;
    }
    print_phonebook();
    int user_to_display;
    std::cout << "Enter a user index to display: ";
    std::cin >> user_to_display;
    while (user_to_display < 1 || user_to_display > index)
    {
        std::cout << "The user with this index does not exist, try again: ";
        std::cin >> user_to_display;
    }
    Contacts[user_to_display - 1].print_contact();
}

std::string PhoneBook::truncate(std::string str)
{
    std::string result;
    if (str.length() > 10)
    {
        result = str.substr(0,9) + ".";
        return (result);
    }
    return (str);
}

void PhoneBook::print_phonebook(void)
{
    std::cout << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First Name"
              << "|" << std::setw(10) << std::right << "Last Name"
              << "|" << std::setw(10) << std::right << "Nickname"
              << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < index; i++)
    {
        std::cout << std::setw(10) << std::right << Contacts[i].id
                << "|" << std::setw(10) << std::right << truncate(Contacts[i].first_name)
                << "|" << std::setw(10) << std::right << truncate(Contacts[i].last_name)
                << "|" << std::setw(10) << std::right << truncate(Contacts[i].nickname)
                << std::endl;
    }
    std::cout << std::endl;
}
