/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:17:14 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:17:15 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

int main()
{
    Zombie *x = NULL;

    x = newZombie("Pik");
    x->announce();
    randomChump("kik");
    delete x;
}