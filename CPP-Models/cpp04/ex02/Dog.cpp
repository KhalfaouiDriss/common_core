#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "Dog created\n";
    _brn = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy Constractor: Dog created\n";
    this->_brn = new Brain(*(other._brn));
}

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    *_brn = *other._brn;
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