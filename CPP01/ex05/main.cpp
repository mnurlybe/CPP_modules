/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:53:21 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/09 17:36:09 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl object; 
    
    object.complain("DEBUG");
    std::cout << std::endl;
    object.complain("INFO");
    std::cout << std::endl;
    object.complain("invalid");
    std::cout << std::endl;
    object.complain("WARNING");
    std::cout << std::endl;
    object.complain("ERROR");
    std::cout << std::endl;
    object.complain("invalid");
    std::cout << std::endl;
    object.complain("ERROR");
    
    return 0;
}