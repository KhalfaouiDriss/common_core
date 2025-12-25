#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
    std::string _ideas[100];
public:
    Brain();
    Brain(Brain& other);
    Brain& operator=(Brain& other);
    ~Brain();
};

#endif