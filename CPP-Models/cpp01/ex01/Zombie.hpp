/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:25 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:26 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(void)
        {
            (void)1;
        }
        Zombie(std::string name);
        void announce( void );
        void setName(std::string name);
        ~Zombie();
};



Zombie *newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif