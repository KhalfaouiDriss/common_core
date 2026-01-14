#ifndef GTLE_HPP
#define GTLE_HPP

#include <iostream>
#include <exception>

class GradeTooLowException : std::exception
{
public:
    virtual const char *what() const throw();    
};


#endif