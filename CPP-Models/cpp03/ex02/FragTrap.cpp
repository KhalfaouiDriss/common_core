#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other)
{
    
}

FragTrap& FragTrap::operator=(FragTrap& other)
{
    this->_name = other.GetName();
    this->_HP = other.GetHP();
    this->_AD = other.GetAD();
    this->_EP = other.GetEP();
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high-five" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->GetName() << " has exit\n";
}