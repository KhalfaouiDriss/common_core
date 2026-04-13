#include "RPN.hpp"

RPN::RPN() : _expression("") {
}

RPN::RPN(std::string expression) : _expression(expression)
{
    CheckExpr();
    ProcessStack();
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

void RPN::ProcessStack()
{
    for (std::string::iterator it = _expression.begin(); it != _expression.end(); ++it)
    {
        if (std::isspace(*it))
            continue;

        if (std::isdigit(*it))
        {
            _stk.push(*it - '0');
        }
        else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            if (_stk.size() < 2)
                throw std::runtime_error("Error");

            int b = _stk.top(); 
            _stk.pop();
            int a = _stk.top();
            _stk.pop();

            if (a < 0 || a > 10 || b < 0 || b > 10)
                throw std::runtime_error("Error");

            if (*it == '+') _stk.push(a + b);
            else if (*it == '-') _stk.push(a - b);
            else if (*it == '*') _stk.push(a * b);
            else if (*it == '/') {
                if (b == 0) throw std::runtime_error("Error: Division by zero");
                _stk.push(a / b);
            }
        }
        else
            throw std::runtime_error("Error");
    }

    if (_stk.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _stk.top() << std::endl;
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_expression = other._expression;
        this->_stk = other._stk;
    }
    return *this;
}

RPN::~RPN()
{
}