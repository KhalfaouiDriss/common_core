#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal& other);
    WrongAnimal& operator=(WrongAnimal& other);
    std::string getType() const;
    void setType(std::string type);
    void makeSound() const;
    virtual ~WrongAnimal();
};

#endif