#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <exception>

class BitcoinExchange
{
private:
    std::map<std::string, float> _DataMap;
    std::string _fileName;

public:
    // Constructor
    BitcoinExchange(std::string fileName);

    // 2. Copy Constructor
    BitcoinExchange(const BitcoinExchange &other);

    // 3. Assignment Operator
    BitcoinExchange &operator=(const BitcoinExchange &other);

    // 4. Destructor
    ~BitcoinExchange();

    std::map<std::string, float> initDataMap();
    void Result();
};