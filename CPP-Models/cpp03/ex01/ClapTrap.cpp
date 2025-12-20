#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(100), _EP(50), _AD(20)
{
    std::cout << "ClapTrap " << _name << " Created\n";
}

ClapTrap::ClapTrap() : _name("Default"), _HP(100), _EP(50), _AD(20)
{
    std::cout << "ClapTrap " << _name << " Created\n";
}

ClapTrap::ClapTrap(ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
    this->setName(other.getName());
    this->setHP(other.getHP());
    this->setEP(other.getEP());
    this->setAD(other.getAD());
    return (*this);
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

void ClapTrap::attack(const std::string &target)
{
    if (this->getHP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " is dead\n";
    }
    if (this->getEP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " has no energy\n";
    }
    std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAD() << " points of damage!\n";
    setEP(getEP() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    setHP(getHP() - amount);
    if (this->getHP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " is dead\n";
        return ;
    }
    std::cout << "ClapTrap " << getName() << " take damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " is dead\n";
    }
    if (this->getEP() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " has no energy\n";
    }
    setHP(getHP() + amount);
    if (getHP() > 10)
        setHP(10);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << getName() << " exit\n";
}