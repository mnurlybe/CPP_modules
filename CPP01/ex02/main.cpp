/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:51:34 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 13:05:33 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout << "MemAdd of str:        " << &str << std::endl;
    std::cout << "MemAdd held by PTR:   " << stringPTR << std::endl;
    std::cout << "MemAdd held by REF:   " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of str :        " << str << std::endl;
    std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by REF: " << stringREF << std::endl;
    
    return 0;
}