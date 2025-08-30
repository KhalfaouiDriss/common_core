#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << "Zombie Object : " << name << " -> Created\n";

    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie Object : " << name << " -> destroyed\n";
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}