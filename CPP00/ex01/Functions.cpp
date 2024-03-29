/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:01:29 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 16:21:43 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::print_contact(void)
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << secret << std::endl;
}

void Contact::fill_contact(int index)
{
    id = index + 1;
    std::cout << "Enter first name: ";
    getline(std::cin, first_name);
    if (std::cin.eof())
        return ;
    while (first_name.length() == 0)
    {
        std::cout << "Empty input, please try again: ";
        getline(std::cin, first_name);
        if (std::cin.eof())
            return ;
    }
    std::cout << "Enter last name: ";
    getline(std::cin, last_name);
    if (std::cin.eof())
        return ;
    while (last_name.length() == 0)
    {
        std::cout << "Empty input, please try again: ";
        getline(std::cin, last_name);
        if (std::cin.eof())
            return ;
    }
    
    std::cout << "Enter nickname: ";
    getline(std::cin, nickname);
    if (std::cin.eof())
        return ;
    while (nickname.length() == 0)
    {
        std::cout << "Empty input, please try again: ";
        getline(std::cin, nickname);
        if (std::cin.eof())
            return ;
    }
    
    std::cout << "Enter phone number: ";
    getline(std::cin, phone_number);
    if (std::cin.eof())
        return ;
    while (phone_number.length() == 0)
    {
        std::cout << "Empty input, please try again: ";
        getline(std::cin, phone_number);
        if (std::cin.eof())
            return ;
    }

    std::cout << "Enter your darkest secret: ";
    getline(std::cin, secret);
    if (std::cin.eof())
        return ;
    while (secret.length() == 0)
    {
        std::cout << "Empty input, please try again: ";
        getline(std::cin, secret);
        if (std::cin.eof())
            return ;
    }
}

PhoneBook::PhoneBook()
{
    index = 0;
    oldest_index = 0;
    overflow = 0;
    std::cout << "Hello, you started My Awesome PhoneBook program :)" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Exiting.. Phonebook is destroyed." << std::endl;
}
    
void    PhoneBook::add()
{
    if (index > 7 && overflow == 0)
        overflow = 1;
    if (overflow)
    {
        index = oldest_index;
        oldest_index += 1;
        if (oldest_index == 8)
            oldest_index = 0;
    }
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
    int user_to_display_max;
    if (std::cin.eof())
        return ;
    if (overflow)
        user_to_display_max = 8;
    else
        user_to_display_max = index;
    std::cout << "Enter a user index to display, available indexex from 1 to " << user_to_display_max << " : ";
    std::cin >> user_to_display;
        
    while (user_to_display < 1 || user_to_display > user_to_display_max)
    {
        std::cout << "The user with this index does not exist, try again.\nAvailable indexex from 1 to " << user_to_display_max << " : ";
        std::cin >> user_to_display;
        if (std::cin.eof())
            return ;
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
    if (overflow)
    {
        for (int i = 0; i < 8; i++)
        {
            std::cout << std::setw(10) << std::right << Contacts[i].id
                    << "|" << std::setw(10) << std::right << truncate(Contacts[i].first_name)
                    << "|" << std::setw(10) << std::right << truncate(Contacts[i].last_name)
                    << "|" << std::setw(10) << std::right << truncate(Contacts[i].nickname)
                    << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            std::cout << std::setw(10) << std::right << Contacts[i].id
                    << "|" << std::setw(10) << std::right << truncate(Contacts[i].first_name)
                    << "|" << std::setw(10) << std::right << truncate(Contacts[i].last_name)
                    << "|" << std::setw(10) << std::right << truncate(Contacts[i].nickname)
                    << std::endl;
        }
    }
    
    std::cout << std::endl;
}
