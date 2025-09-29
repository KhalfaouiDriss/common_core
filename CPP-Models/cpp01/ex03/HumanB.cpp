/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:53 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:54 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) 
    : name(name)
{
    std::cout << "* HumanB : " << name << " Created\n";
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->club->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &club)
{
    this->club = &club;
}