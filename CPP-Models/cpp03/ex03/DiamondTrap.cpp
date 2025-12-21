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
    _HP = FragTrap::_HP;   // 100
    _EP = ScavTrap::_EP;  // 50
    _AD = FragTrap::_AD;  // 30

    std::cout << "DiamondTrap " << _dname << " created\n";
}



DiamondTrap::~DiamondTrap()
{
}