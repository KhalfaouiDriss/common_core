#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    void makeSound();
    void print()
    {
        std::cout << "hello";
    }
    ~Cat();
};


#endif