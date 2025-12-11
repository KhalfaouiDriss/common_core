#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _HP = 100;
    _AD = 30;
    _EP = 100;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _HP = 100;
    _AD = 30;
    _EP = 100;
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
    std::cout << _name << " requests a positive high-five" << std::endl;
}

FragTrap::~FragTrap()
{
    // std::cout << this->GetName() << " has exit\n";
}