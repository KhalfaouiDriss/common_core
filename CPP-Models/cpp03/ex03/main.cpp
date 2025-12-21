#include "DiamondTrap.hpp"
// #include <iostream>

int main()
{
    // DiamondTrap evil("driss");
    // DiamondTrap devil;
    // devil = evil;
    // devil.whoAmI();
    // devil.attack("enm");
    // devil.highFivesGuys();
    DiamondTrap diam("diam");

    std::cout << "Nmae : " << diam.getName() << " | HP : " << diam.getHP() << " | EP : " << diam.getEP() << " | AD : " << diam.getAD() << "\n";

    return 0;
}
