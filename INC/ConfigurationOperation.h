#pragma once
#include "MiscEnums.h"

class ConfigurationOperation
{
protected:
    CONFIGURATION m_configuration;
public:
    ConfigurationOperation();
    virtual ~ConfigurationOperation();
    ConfigurationOperation(const ConfigurationOperation& obj) = delete;
    ConfigurationOperation& operator = (const ConfigurationOperation& obj) = delete;
    virtual void parseConfiguration() = 0;

    const CONFIGURATION& getConfiguration() const;

};
