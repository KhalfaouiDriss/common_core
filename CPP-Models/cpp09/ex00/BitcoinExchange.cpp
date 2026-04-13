#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName)
{
    if (fileName.length() < 4 || fileName.rfind(".txt") != (fileName.length() - 4)) 
        throw std::runtime_error("Error: Invalid file extension. Expected .txt");

    this->_DataMap = initDataMap();
}

// Data file process :

std::map<std::string, float> BitcoinExchange::initDataMap()
{
    std::ifstream file("../cpp_09/data.csv");
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::string header;
    std::map<std::string, float> tempMap;
    std::getline(file, header);

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        size_t delPos = line.find(',');
        if (delPos == std::string::npos) continue;

        std::string date = line.substr(0, delPos);
        std::string strPrice = line.substr(delPos + 1);

        float price = std::atof(strPrice.c_str());
        
        tempMap[date] = price;
    }
    file.close();
    return tempMap;
}

// Input file process :

void BitcoinExchange::execute()
{
    std::ifstream file(this->_fileName.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::map<std::string, float>::iterator itData;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        size_t delPos = line.find('|');
        if (delPos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delPos);
        date.erase(date.find_last_not_of(" \t") + 1); 
        
        std::string strPrice = line.substr(delPos + 1);
        
        float price = static_cast<float>(std::atof(strPrice.c_str()));
        if (price < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (price > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        itData = _DataMap.lower_bound(date);

        if (itData != _DataMap.begin() && (itData == _DataMap.end() || itData->first != date))
            --itData;

        if (itData != _DataMap.end() && itData->first <= date)
        {
            float result = price * itData->second;
            std::cout << date << " => " << price << " = " << result << std::endl;
        }
        else
        {
            std::cout << "Error: bad input => " << date << std::endl;
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other) {
        this->_fileName = other._fileName;
        this->_DataMap = other._DataMap;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
