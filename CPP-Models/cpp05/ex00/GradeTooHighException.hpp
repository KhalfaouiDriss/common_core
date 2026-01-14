#ifndef GTHE_HPP
#define GTHE_HPP

#include <iostream>

class GradeTooHighException
{
public:
    virtual const char *what() const throw();
};


#endif