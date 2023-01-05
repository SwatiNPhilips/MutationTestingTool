#pragma once
#include<string>
#include <iostream>
#include<vector>
#include"MiscEnums.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
using namespace std;

using namespace std;
class ConfigurationParser
{
    std::string m_abspath;
    CONFIGURATION m_configuration;
public:

	ConfigurationParser(std::string);
	~ConfigurationParser();
    void parseConfiguration();
    CONFIGURATION getConfiguration() const;
};