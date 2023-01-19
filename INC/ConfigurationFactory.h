#pragma once
#include "MiscEnums.h"
#include "ConfigurationOperation.h"

class ConfigurationFactory
{
    CONFIGURATION_TYPE m_confType;
public:
    ConfigurationFactory();
    ~ConfigurationFactory();

    ConfigurationOperation* getConfigurationType() const;
    void SetConfigurationType(const CONFIGURATION_TYPE type);
};
