/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:22 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:23 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << "Zombie Object : " << name << " -> Created\n";

    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie Object : " << _name << " -> destroyed\n";
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ\n";
}

void Zombie::setName(std::string name)
{
    std::cout << "Zombie Object : " << name << " -> Created\n";
    this->_name = name;
}