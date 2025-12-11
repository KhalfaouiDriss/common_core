#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    :
    ClapTrap("unknown_clap_name"), 
    ScavTrap(),   
    FragTrap(),   
    _dname("unknown")       
{
}

DiamondTrap::DiamondTrap(std::string name)
    : 
    ClapTrap(name + "_clap_name"),
    ScavTrap(name),            
    FragTrap(name),            
    _dname(name)               
{
    this->_HP = FragTrap::_HP;
    this->_EP = ScavTrap::_EP;
    this->_AD = FragTrap::_AD;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _dname << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
}