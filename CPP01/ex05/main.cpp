/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:53:21 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/01 14:53:42 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl object; 
    
    object.complain("DEBUG");
    object.complain("INFO");
    object.complain("invalid");
    object.complain("WARNING");
    object.complain("ERROR");
    object.complain("invalid");
    
    return 0;
}