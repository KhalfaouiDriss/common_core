/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:08 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:09 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 


int main()
{
    Zombie *newZomb = NULL;
    Zombie *zombHorde = NULL;
    
    newZomb = newZombie("newZombie");
    newZomb->announce();
    std::cout << "======================\n";
    randomChump("randomChump");
    std::cout << "======================\n";
    zombHorde = zombieHorde(10 ,"zombHorde");

    delete newZomb;
    delete[] zombHorde;
}