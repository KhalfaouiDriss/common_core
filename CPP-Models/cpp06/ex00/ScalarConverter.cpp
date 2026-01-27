#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

void ScalarConverter::convert(std::string target)
{
    std::cout << "char : " << static_cast<char>(std::stoi(target)) << std::endl;
    std::cout << "int : " << static_cast<int>(std::stoi(target)) << std::endl;
    std::cout << "float : " << static_cast<float>(std::stof(target)) << std::endl;
    // std::cout << "" << target << std::endl;
}

ScalarConverter::~ScalarConverter()
{
}