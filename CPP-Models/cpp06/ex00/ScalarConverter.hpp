#include <iostream>
#include <cstdlib>

class ScalarConverter
{
private:
    ScalarConverter(/* args */);
public:
    static void convert(const std::string target);
    ~ScalarConverter();
};

