#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int _HP;
    int _EP;
    int _AD;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap& other);
    
    // Getter
    std::string GetName();
    int GetHP();
    int GetEP();
    int GetAD();
    // Setter
    void SetName(std::string Name);
    void SetHP(int HP);
    void SetEP(int EP);
    void SetAD(int AD);

    ClapTrap& operator=(ClapTrap& other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ~ClapTrap();
};

#endif