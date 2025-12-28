#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    WrongAnimal::operator=(other);
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "meaw\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat deleted\n";
}