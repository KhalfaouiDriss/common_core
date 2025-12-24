#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "Dog created\n";
}

void Dog::makeSound()
{
    std::cout << "woaf\n";
}

Dog::~Dog()
{
    std::cout << "Dog deleted\n";
}