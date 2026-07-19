#include "bigint.hpp"

bigint::bigint() : _value("0"){}

bigint::bigint(const std::string val) : _value(val)
{
    std::reverse(_value.begin(), _value.end());
}

bigint::bigint(const unsigned int val)
{
    (val <= 0) ? _value = "0" : _value = std::to_string(val);
    std::reverse(_value.begin(), _value.end());
}

// bigint::bigint(const bigint& other)
// {

// }

// bigint& bigint::operator=(const bigint& other)
// {
    
// }

// addition operations
bigint bigint::operator+(const bigint& other)
{
    bigint final;
    std::string s1 = _value, s2 = other._value;
    int rest = 0, size, i = -1;
    (_value.size() > other._value.size()) ? size = _value.size() : other._value.size();

    while (++i < size)
    {
        int num1 = (s1.size() > i) ? s1[i] - '0' : 0;
        int num2 = (s2.size() > i) ? s2[i] - '0' : 0;
        int sum = num1 + num2;
        rest = sum / 10;
        int result = sum % 10;
        final._value.push_back(result + '0');
    }
    return final;
}

// bigint& bigint::operator++()
// {
//     // type the code here
// }

// bigint& bigint::operator++(int)
// {
//     // type the code here
// }

// bigint& bigint::operator+=(const bigint& other)
// {
//     // type the code here
// }

// // comparison operation
// {
//     // type the code here
// }

// bool bigint::operator<(const bigint& other)
// {
//     // type the code here
// }

// bool bigint::operator<=(const bigint& other)
// {
//     // type the code here
// }

// bool bigint::operator>(const bigint& other)
// {
//     // type the code here
// }

// bool bigint::operator>=(const bigint& other)
// {
//     // type the code here
// }

// bool bigint::operator==(const bigint& other)
// {
//     // type the code here
// }

// bool bigint::operator!=(const bigint& other)
// {
//     // type the code here
// }

// // digitshift operation
// {
//     // type the code here
// }

// bigint& bigint::operator<<(const bigint& other)
// {
//     // type the code here
// }

// bigint& bigint::operator>>(const bigint& other)
// {
//     // type the code here
// }


bigint::~bigint()
{
}