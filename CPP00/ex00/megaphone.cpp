/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:19:07 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/23 15:08:13 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        int i = 0, j = 0;
        while (++i < argc)
        {
            j = -1;
            while (argv[i][++j] != '\0')
                std::cout << (char)toupper(argv[i][j]);
        }
    }
    std::cout << std::endl;
    return 0;
}