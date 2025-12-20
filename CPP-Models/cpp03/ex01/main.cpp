#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ScavTrap b("Bravo");

    a.attack("Bravo");
    b.takeDamage(5);

    std::cout << b.getHP() << "\n";
    
    b.beRepaired(3);
    b.attack("Alpha");
    b.guardGate();

    return 0;
}
