#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << "Zombie Object : " << name << " -> Created\n";
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie Object : " << _name << " -> destroyed\n";
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}