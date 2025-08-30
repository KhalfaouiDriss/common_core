#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *tmp = new Zombie[N];
    int i = -1;

    while (++i < N) {tmp[i].setName(name); tmp[i].announce();}
    return tmp;
}