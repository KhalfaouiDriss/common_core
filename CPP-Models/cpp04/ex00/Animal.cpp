#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal obj created\n";
}

void Animal::makeSound()
{
    std::cout << "Animal default sound \n";
}

Animal::Animal(Animal& other)
{
    *this = other;
}
Animal& Animal::operator=(Animal& other)
{
    this->_type = other._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal obj deleted\n";
}