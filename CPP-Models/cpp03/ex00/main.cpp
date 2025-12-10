#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b;

    a.attack("Bravo");
    b.takeDamage(3);
    b.beRepaired(2);

    return 0;
}
