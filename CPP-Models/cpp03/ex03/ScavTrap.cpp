#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _HP = 100;
    _AD = 20;
    _EP = 50;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    _HP = 100;
    _AD = 20;
    _EP = 50;
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other)
{
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << GetName() << " is now in Gate keeper mode.\n";
}

ScavTrap::~ScavTrap()
{
    // std::cout << this->GetName() << " has exit\n";
}