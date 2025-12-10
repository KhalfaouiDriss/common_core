#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other)
{
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
    this->_name = other.GetName();
    this->_HP = other.GetHP();
    this->_AD = other.GetAD();
    this->_EP = other.GetEP();
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << GetName() << " is now in Gate keeper mode.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << this->GetName() << " has exit\n";
}