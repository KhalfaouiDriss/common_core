/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:17:53 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:17:54 by dkhalfao         ###   ########.fr       */
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
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}