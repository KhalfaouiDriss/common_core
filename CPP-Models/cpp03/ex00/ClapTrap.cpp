#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("unknown"), _HP(10), _EP(10), _AD(0)
{
}

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _HP(10), _EP(10), _AD(0)
{
}

ClapTrap::ClapTrap(ClapTrap& other)
{
    *this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
    this->_name = other.GetName();
    this->_HP = other.GetHP();
    this->_AD = other.GetAD();
    this->_EP = other.GetEP();
    return (*this);
}

std::string ClapTrap::GetName()
{
    return (this->_name);
}

int ClapTrap::GetHP()
{
    return (this->_HP);
}

int ClapTrap::GetEP()
{
    return (this->_EP);
}

int ClapTrap::GetAD()
{
    return (this->_AD);
}

void ClapTrap::SetName(std::string Name)
{
    _name = Name;
}

void ClapTrap::SetHP(int HP)
{
    this->_HP = HP;
}

void ClapTrap::SetEP(int EP)
{
    this->_EP = EP;
}

void ClapTrap::SetAD(int AD)
{
    this->_AD = AD;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->GetHP() <= 0)
    {
        std::cout << "ClapTrap " << this->GetName() << " is dead\n";
        return ;
    }
    if (this->GetEP() <= 0)
    {
        std::cout << "ClapTrap " << this->GetName() << " has no energy\n";
        return ;
    }

    std::cout << "ClapTrap " << this->GetName() 
              << " attacks " << target 
              << ", causing " << this->GetAD() << " points of damage!\n";

    this->SetEP(this->GetEP() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->GetHP() <= 0)
    {
        std::cout << "ClapTrap " << this->GetName() << " is dead\n";
        return ;
    }

    std::cout << "ClapTrap " << this->GetName() 
              << " takes " << amount << " points of damage!\n";

    int newHP = this->GetHP() - amount;
    if (newHP < 0)
        newHP = 0;

    this->SetHP(newHP);
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->GetHP() <= 0)
    {
        std::cout << "ClapTrap " << this->GetName() << " is dead\n";
        return ;
    }
    if (this->GetEP() <= 0)
    {
        std::cout << "ClapTrap " << this->GetName() << " has no energy\n";
        return ;
    }

    std::cout << "ClapTrap " << this->GetName() 
              << " is repaired for " << amount << " hit points!\n";

    this->SetHP(this->GetHP() + amount);
    this->SetEP(this->GetEP() - 1);
}

ClapTrap::~ClapTrap()
{
}
