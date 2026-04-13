#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <stack>
#include <algorithm>

class RPN
{
private:
    std::string _expression;
    std::stack<int> _stk;

public:
    // 1. Default Constructor
    RPN();

    // Parameterized Constructor
    RPN(std::string expression);

    // 2. Copy Constructor
    RPN(const RPN &other);

    // 3. Assignment Operator
    RPN &operator=(const RPN &other);

    int CheckExpr();
    void ProcessStack();

    // 4. Destructor
    ~RPN();
};

