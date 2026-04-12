#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <exception>

class BitcoinExchange
{
private:
    std::map<std::string, float> _DataMap;
    std::string _Data;
    std::string _fileName;
public:
    BitcoinExchange(std::string fileName);
    // std::string initData();
    std::map<std::string, float> initDataMap();
    int processDate(std::string date);
    int processPrice(std::string price);
    void DisplayBTCStatictic(); 
    // ~BitcoinExchange();
};