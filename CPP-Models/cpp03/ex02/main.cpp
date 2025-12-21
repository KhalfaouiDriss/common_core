#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap scav("Scavvy");
    scav.attack("enemy");
    scav.guardGate();
    FragTrap frag("Fraggy");
    frag.takeDamage(20);
    frag.attack("enemy");
    frag.highFivesGuys();

    return 0;
}
