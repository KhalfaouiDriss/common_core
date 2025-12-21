#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _dname;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
};



#endif