#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club)
    : name(name), club(&club)
{
    std::cout << "* HumanA : " << name << " Created\n";
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->club->getType() << std::endl;
}