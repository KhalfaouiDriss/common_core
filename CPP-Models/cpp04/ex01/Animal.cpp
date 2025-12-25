#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal obj created\n";
}

void Animal::makeSound() const
{
    std::cout << "Animal default sound \n";
}

Animal::Animal(Animal& other)
{
    *this = other;
}
Animal& Animal::operator=(Animal& other) 
{
    this->_type = other.getType();
    return (*this);
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::setType(std::string type)
{
    this->_type = type;
}

Animal::~Animal()
{
    std::cout << "Animal obj deleted\n";
}