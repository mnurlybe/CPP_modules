/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:37:27 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 17:55:55 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 4){
        std::cerr << "wrong number of arguments" << std::endl;
        return 1;
    }
    else
        std::cout << "ok" << std::endl;
    return 0;
}