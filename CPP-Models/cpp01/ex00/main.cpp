#include "Zombie.hpp" 

int main()
{
    Zombie *x = NULL;

    x = newZombie("Pik");
    x->announce();
    randomChump("kik");
    // delete x;
}