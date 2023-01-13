#include "ConfigurationFactory.h"
#include "ConfigurationJSONParser.h"

ConfigurationFactory::ConfigurationFactory()
{
    m_confType = CONFIGURATION_TYPE::DEFAULT;
}

ConfigurationFactory::~ConfigurationFactory()
{
    m_confType = CONFIGURATION_TYPE::DEFAULT;
}

void ConfigurationFactory::SetConfigurationType(const CONFIGURATION_TYPE type)
{
    m_confType = type;
}

ConfigurationOperation* ConfigurationFactory::getConfigurationType() const
{
    ConfigurationOperation* confFile = nullptr;
    switch (m_confType)
    {
        case JSON:
            confFile = ConfigurationJSONParser::GetInstance();
            break;
        default:
            break;
    }
    return confFile;
}
