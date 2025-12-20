#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap " << getName() << " Created\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
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

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " exit\n";
}