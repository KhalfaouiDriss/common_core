#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <algorithm>

class RPN
{
private:
    std::string _expression;
public:
    RPN(std::string expression);
    int CheckExpr();
    ~RPN();
};

