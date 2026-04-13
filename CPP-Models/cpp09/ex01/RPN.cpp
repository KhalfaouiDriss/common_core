#include "RPN.hpp"

RPN::RPN(std::string expression) : _expression(expression)
{
    CheckExpr();
}

int RPN::CheckExpr()
{
    std::string::iterator it = _expression.begin();

    while (it != _expression.end())
    {
        if(!isdigit(*it) && *it != '*' && *it != '+' && *it != '-' && *it != '/' && *it != ' ')
            throw std::runtime_error("Error");
        it++;
    }
    return 0;
}

RPN::~RPN()
{
}