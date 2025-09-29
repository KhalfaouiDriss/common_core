/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:42 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:43 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club)
    : name(name), club(club)
{
    std::cout << "* HumanA : " << name << " Created\n";
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->club.getType() << std::endl;
}