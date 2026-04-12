#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName)
{
    if (fileName.length() < 4 || fileName.rfind(".csv") != (fileName.length() - 4)) 
        throw std::runtime_error("Error: Invalid file extension. Expected .csv");

    // this->_Data = initData();
    this->_DataMap = initDataMap();

}

std::map<std::string, float> BitcoinExchange::initDataMap()
{
    std::ifstream file(this->_fileName);
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::string header;
    
    std::getline(file, header);

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        size_t delPos = line.find(',');
        if (delPos == std::string::npos) continue;

        std::string date = line.substr(0, delPos);
        std::string strPrice = line.substr(delPos + 1);

        processDate(date);

        float price = std::atof(strPrice.c_str());
        
        _DataMap[date] = price;
    }
    return _DataMap;
}

int BitcoinExchange::processDate(std::string date)
{


    // erase "-"
    std::string newDate;
    if((newDate = date.erase('-')) == date.end())
        std::cout << newDate << "\n";
    // newDate = newDate.erase('-');
    // newDate = newDate.erase('-');

    // std::string tok = date.substr(0, 3);
    // std::cout << tok;
    // tok = date.substr(5, 7);
    // std::cout << tok;
    // tok = date.substr(8, 10);
    // std::cout << tok << std::endl;
    // std::cout << "=========\n";
    
    return 0;
}
// std::string BitcoinExchange::initData()
// {

// }



void BitcoinExchange::DisplayBTCStatictic()
{
    // std::map<std::string, float>::iterator it = _DataMap.begin();
    // while (it != _DataMap.end())
    // {
    //     std::cout << it->first << " => " << it->second << std::endl;
    //     it++;
    // }
}

// BitcoinExchange::~BitcoinExchange()
// {
// }
