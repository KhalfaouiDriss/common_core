#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    setHP(100);
    setEP(100);
    setAD(30);
    std::cout << "FragTrap " << getName() << " Created\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHP(100);
    setEP(100);
    setAD(30);
    std::cout << "FragTrap " << getName() << " Created\n";
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other)
{
}

FragTrap& FragTrap::operator=(FragTrap& other)
{
    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " request a positive high-fives\n"; 
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " exit\n";
}