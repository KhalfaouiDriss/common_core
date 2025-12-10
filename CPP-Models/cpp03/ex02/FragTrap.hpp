#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap& other);
    FragTrap& operator=(FragTrap& other);
    void highFivesGuys(void);
    ~FragTrap();
};


#endif