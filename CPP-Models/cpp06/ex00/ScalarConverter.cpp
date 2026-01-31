#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
        literal == "+inff" || literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal.find("nan") != std::string::npos)
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else
        {
            std::cout << "float: " << (literal[0] == '+' ? "+inff" : "-inff") << std::endl;
            std::cout << "double: " << (literal[0] == '+' ? "+inf" : "-inf") << std::endl;
        }
        return;
    }

    char *endPtr;
    double val = std::strtod(literal.c_str(), &endPtr);

    std::cout << "char: ";
    if (val < CHAR_MIN || val > CHAR_MAX || std::isnan(val))
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << "int: ";
    if (val < INT_MIN || val > INT_MAX || std::isnan(val))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}