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
    void makeSound();
    ~Animal();
};


#endif