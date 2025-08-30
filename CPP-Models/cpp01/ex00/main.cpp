#include "Zombie.hpp" 


int main()
{
    Zombie *x = NULL;
    
    x = newZombie("Driss");
    x->announce();
    randomChump("kik");
    delete x;
}