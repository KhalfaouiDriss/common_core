/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:17:57 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:17:58 by dkhalfao         ###   ########.fr       */
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
        Zombie(std::string name);
        void announce( void );
        ~Zombie();
};



Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif