#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(ScavTrap& other);
    ScavTrap& operator=(ScavTrap& other);
    void guardGate();
    ~ScavTrap();
};




#endif