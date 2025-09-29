/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:06 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:19:07 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    std::cout << "* Weapon : " << type << " Created\n";
    this->type = type; 
}

std::string Weapon::getType()
{
    return this->type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}