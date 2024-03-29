/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:53:21 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 19:13:19 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl object; 
    
    object.complain("DEBUG");
    object.complain("INFO");
    object.complain("WARNING");
    object.complain("ERROR");
    object.complain("invalid");
    
    return 0;
}