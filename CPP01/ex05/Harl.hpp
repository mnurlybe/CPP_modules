/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:53:37 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/09 17:36:49 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void invalid(void);
    
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};

typedef void (Harl::*fptr)(void);

#endif