#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    Animal(Animal& other);
    Animal& operator=(Animal& other);
    std::string getType() const;
    void setType(std::string type);
    virtual void makeSound() const = 0;
    virtual ~Animal();
};

#endif