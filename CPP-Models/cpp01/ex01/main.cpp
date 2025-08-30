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