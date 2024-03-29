/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:32:31 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/03/29 17:11:46 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon& weapon;
    
    public:
        HumanA(std::string name, Weapon& weapon_type);
        ~HumanA();
        void attack();
};

#endif