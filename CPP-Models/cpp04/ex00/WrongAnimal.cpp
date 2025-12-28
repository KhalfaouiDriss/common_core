#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal obj created\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal default sound \n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
    this->_type = other.getType();
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal obj deleted\n";
}