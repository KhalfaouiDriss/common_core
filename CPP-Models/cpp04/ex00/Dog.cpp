#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
}

Dog& Dog::operator=(const Dog& other)
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
    std::cout << "Dog deleted\n";
}