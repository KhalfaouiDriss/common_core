#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _dname("Default")
{
    std::cout << "ClapTrap " << getName() << " Created\n";
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(),
      FragTrap(),
      _dname(name)
{
    this->_HP = 100;
    this->_EP = 50;
    this->_AD = 30;
    std::cout << "DiamondTrap " << _dname << " created\n";
}

DiamondTrap::DiamondTrap(DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other)
{
    ClapTrap::operator=(other);
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name : " << this->_dname << " ClapTrap name : " << this->getName() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamonTrap " << _dname << " exit\n";
}