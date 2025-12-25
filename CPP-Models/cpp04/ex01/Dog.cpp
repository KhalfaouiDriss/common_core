#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    _brn = new Brain();
    std::cout << "Dog created\n";
}

Dog::Dog(Dog& other) : Animal(other)
{
}

Dog& Dog::operator=(Dog& other)
{
    Animal::operator=(other);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "woaf\n";
}

Dog::~Dog()
{
    delete _brn;
    std::cout << "Dog deleted\n";
}