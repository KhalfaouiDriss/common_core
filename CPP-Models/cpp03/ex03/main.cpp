#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap evil("driss");
    DiamondTrap devil;
    devil = evil;
    devil.whoAmI();
    devil.attack("enm");
    devil.highFivesGuys();

    return 0;
}
