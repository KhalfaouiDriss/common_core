#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "Dog created\n";
    _brn = new Brain();
}

Dog::Dog(Dog& other) : Animal(other)
{
    this->_brn = other._brn;
}

Dog& Dog::operator=(Dog& other)
{
    Animal::operator=(other);
    delete this->_brn;
    this->_brn = new Brain(*(other._brn));
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