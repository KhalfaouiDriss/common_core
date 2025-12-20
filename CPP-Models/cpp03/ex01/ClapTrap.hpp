#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int _HP;
    int _EP;
    int _AD;
public:
    ClapTrap(std::string name);
    ClapTrap();

    void setName(std::string name);
    void setHP(int HP);
    void setEP(int EP);
    void setAD(int AD);

    std::string getName();
    int getHP();
    int getEP();
    int getAD();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    ClapTrap(ClapTrap& other);
    ClapTrap& operator=(ClapTrap& other);
    ~ClapTrap();
};


#endif
