#include "HumanB.hpp"

HumanB::HumanB(std::string name) 
    : name(name)
{
    std::cout << "* HumanB : " << name << " Created\n";
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->club->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &club)
{
    this->club = &club;
}