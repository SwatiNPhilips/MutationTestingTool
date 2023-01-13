#pragma once
#include "MiscEnums.h"

class ConfigurationManager
{
    CONFIGURATION m_configuration;
public:
    ConfigurationManager();
    ~ConfigurationManager();
    ConfigurationManager(const ConfigurationManager& obj) = delete;
    ConfigurationManager& operator = (const ConfigurationManager& obj) = delete;

    const CONFIGURATION& PopulateConfigStruct(const CONFIGURATION_TYPE& config_type);
};