/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:53:21 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/01 15:16:04 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Wrong amount of arguments." << std::endl;
        std::cout << "Input: [DEBUG], [INFO], [WARNING], [INFO]" << std::endl;
        return 1;
    }

    Harl harl; 
    harl.complain(argv[1]);
    
    return 0;
}