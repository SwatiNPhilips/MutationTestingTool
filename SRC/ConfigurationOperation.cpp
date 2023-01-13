#include "ConfigurationOperation.h"

ConfigurationOperation::ConfigurationOperation()
{
    m_configuration.clear();
}

ConfigurationOperation::~ConfigurationOperation()
{
    m_configuration.clear();
}

const CONFIGURATION& ConfigurationOperation::getConfiguration() const
{
    return m_configuration;
}