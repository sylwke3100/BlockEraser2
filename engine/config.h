#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "boost/lexical_cast.hpp"

class Config
{
    std::string Buffer;
    std::map <std::string, std::string> values;
public:
    Config(std::string fileName);
    void parse();
    int getIntValue(std::string key, int defaultValue);
    std::string getStringValue(std::string key, std::string defaultValue);

};

#endif // CONFIG_H
