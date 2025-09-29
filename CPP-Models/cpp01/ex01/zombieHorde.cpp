/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:31 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:32 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *tmp = new Zombie[N];
    int i = -1;

    while (++i < N) {tmp[i].setName(name); tmp[i].announce();}
    return tmp;
}