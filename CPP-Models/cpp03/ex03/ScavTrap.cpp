#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    setHP(100);
    setEP(50);
    setAD(20);
    std::cout << "ScavTrap " << getName() << " Created\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHP(100);
    setEP(50);
    setAD(20);
    std::cout << "ScavTrap " << getName() << " Created\n";
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
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " exit\n";
}