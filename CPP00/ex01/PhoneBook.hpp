/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:10 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/23 20:34:03 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    public:
        int         id;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
    
    void print_contact(void)
    {
        std::cout << "ID: " << id << std::endl;
        std::cout << "First name: " << first_name << std::endl;
        std::cout << "Last name: " << last_name << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phone_number << std::endl;
        std::cout << "Darkest Secret: " << secret << std::endl;
    }
    
    void fill_contact(int index)
    {
        id = index + 1;
        std::cout << "Enter first name: ";
        std::cin.ignore();
        getline(std::cin, first_name);
        while (first_name.length() == 0)
        {
            std::cout << "Empty input, please try again: ";
            getline(std::cin, first_name);
        }
        std::cout << "Enter last name: ";
        getline(std::cin, last_name);
        while (last_name.length() == 0)
        {
            std::cout << "Empty input, please try again: ";
            getline(std::cin, last_name);
        }
        
        std::cout << "Enter nickname: ";
        getline(std::cin, nickname);
        while (nickname.length() == 0)
        {
            std::cout << "Empty input, please try again: ";
            getline(std::cin, nickname);
        }
        
        std::cout << "Enter phone number: ";
        getline(std::cin, phone_number);
        while (phone_number.length() == 0)
        {
            std::cout << "Empty input, please try again: ";
            getline(std::cin, phone_number);
        }

        std::cout << "Enter your darkest secret: ";
        getline(std::cin, secret);
        while (secret.length() == 0)
        {
            std::cout << "Empty input, please try again: ";
            getline(std::cin, secret);
        }
    }
};

class PhoneBook
{
    private:
        Contact Contacts[8];
        std::string truncate(std::string str);

    public:
        int index;

        PhoneBook()
        {
            index = 0;
            std::cout << "Hello, you started My Awesome PhoneBook program :)" << std::endl;
        }
        
        ~PhoneBook()
        {
            std::cout << "Exiting.. Phonebook is destroyed." << std::endl;
        }

        void    add();
        void    search();
        void print_phonebook(void);
};

#endif