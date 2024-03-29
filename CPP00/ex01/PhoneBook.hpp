/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:10 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 15:46:38 by mnurlybe         ###   ########.fr       */
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
    
    void print_contact(void);
    void fill_contact(int index);
};

class PhoneBook
{
    private:
        Contact Contacts[8];
        std::string truncate(std::string str);

    public:
        int index;
        int oldest_index;
        int overflow;

        PhoneBook();
        ~PhoneBook();
        void    add();
        void    search();
        void print_phonebook(void);
        void update_flag();
};

#endif