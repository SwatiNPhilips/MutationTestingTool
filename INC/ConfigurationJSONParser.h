#pragma once
#include "MiscEnums.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include "ConfigurationOperation.h"

class ConfigurationJSONParser: public ConfigurationOperation
{
public:

    ConfigurationJSONParser();
    ~ConfigurationJSONParser();
    ConfigurationJSONParser(const ConfigurationJSONParser& obj) = delete;
    ConfigurationJSONParser& operator = (const ConfigurationJSONParser& obj) = delete;

    virtual void parseConfiguration() override;

    static ConfigurationJSONParser* GetInstance()
    {
        static ConfigurationJSONParser obj;
        return &obj;
    }
};