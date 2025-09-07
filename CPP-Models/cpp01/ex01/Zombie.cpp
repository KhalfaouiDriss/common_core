#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << "Zombie Object : " << name << " -> Created\n";

    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie Object : " << name << " -> destroyed\n";
    delete
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}

void Zombie::setName(std::string name)
{
    std::cout << "Zombie Object : " << name << " -> Created\n";
    this->name = name;
}