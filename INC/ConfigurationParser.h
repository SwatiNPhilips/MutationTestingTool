#pragma once
#include"MiscEnums.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class ConfigurationParser
{
    string m_abspath;
    CONFIGURATION m_configuration;
public:

	ConfigurationParser(string);
	~ConfigurationParser();
    void parseConfiguration();
    CONFIGURATION getConfiguration() const;
};