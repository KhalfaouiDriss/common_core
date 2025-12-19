#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AD(0)
{
    std::cout << "ClapTrap " << _name << " Created\n";
}

ClapTrap::ClapTrap() : _name("Default"), _HP(10), _EP(10), _AD(0)
{
    std::cout << "ClapTrap " << _name << " Created\n";
}

ClapTrap::ClapTrap(ClapTrap& other)
{
    *this = other;
}
ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
    this->setName(other.getName());
    this->setHP(other.getHP());
    this->setEP(other.getEP());
    this->setAD(other.getAD());
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}
void ClapTrap::setHP(int HP)
{
    this->_HP = HP;
}
void ClapTrap::setEP(int EP)
{
    this->_EP = EP;
    
}
void ClapTrap::setAD(int AD)
{
    this->_AD = AD;
    
}

std::string ClapTrap::getName()
{
    return (_name);
}
int ClapTrap::getHP()
{
    return (_HP);
}
int ClapTrap::getEP()
{
    return (_EP);
}
int ClapTrap::getAD()
{
    return (_AD);
}

ClapTrap::~ClapTrap()
{
}