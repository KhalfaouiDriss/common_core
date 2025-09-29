/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:10 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:19:11 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
# define WEAPON

#include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string type);
        std::string getType();
        void setType(std::string type);
    
};

#endif