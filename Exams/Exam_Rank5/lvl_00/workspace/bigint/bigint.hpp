#include <iostream>
#include <string>
#include <bits/stdc++.h>


class bigint
{
private:
    std::string _value;
public:
    bigint();
    bigint(const std::string val);
    bigint(const unsigned int val);
    
    // bigint(const bigint& other);
    // bigint& operator=(const bigint& other)

    // // addition operations
    bigint operator+(const bigint& other);
    // bigint& operator++();
    // bigint& operator++(int);
    // bigint& operator+=(const bigint& other);
    
    // // comparison operations
    // bigint& operator<(const bigint& other);
    // bigint& operator<=(const bigint& other);
    // bigint& operator>(const bigint& other);
    // bigint& operator>=(const bigint& other);
    // bigint& operator==(const bigint& other);
    // bigint& operator!=(const bigint& other);

    // // digitshift operations
    // bigint& operator<<(const bigint& other);
    // bigint& operator>>(const bigint& other);

    // destractor
    ~bigint();

    // debug fct
    int debug()
    {
        std::cout << "value is : " << _value << std::endl;
        return 0;
    }
};
