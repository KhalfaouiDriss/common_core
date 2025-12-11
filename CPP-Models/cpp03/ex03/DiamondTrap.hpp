#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _dname;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    // DiamondTrap(DiamondTrap& other);
    // DiamondTrap& operator=(DiamondTrap& other);
    void attack(const std::string& target);
    void whoAmI();
    ~DiamondTrap();
};



#endif