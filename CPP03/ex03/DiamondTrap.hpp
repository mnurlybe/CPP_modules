/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:01:20 by julienmoign       #+#    #+#             */
/*   Updated: 2024/04/08 15:32:31 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP


# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name_input);
        DiamondTrap(const DiamondTrap &obj);
        ~DiamondTrap();

        DiamondTrap &operator=(const DiamondTrap &obj);
        
        void whoAmI();
};
#endif