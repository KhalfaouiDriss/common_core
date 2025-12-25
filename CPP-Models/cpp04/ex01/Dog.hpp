#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* _brn;
public:
    Dog();
    Dog(Dog& other);
    Dog& operator=(Dog& other);
    void makeSound() const;
    ~Dog();
};

#endif