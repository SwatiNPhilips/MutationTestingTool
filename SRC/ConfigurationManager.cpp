#include "ConfigurationManager.h"
#include "ConfigurationFactory.h"

ConfigurationManager::ConfigurationManager()
{
    m_configuration.clear();
}
ConfigurationManager::~ConfigurationManager()
{
    m_configuration.clear();
}

const CONFIGURATION& ConfigurationManager::PopulateConfigStruct(const CONFIGURATION_TYPE& config_type)
{
    shared_ptr<ConfigurationFactory> p_configFactory(make_shared<ConfigurationFactory>());
    if (p_configFactory != nullptr)
    {
        p_configFactory->SetConfigurationType(config_type);
        ConfigurationOperation* p_config = p_configFactory->getConfigurationType();
        if(p_config != nullptr)
        {
            p_config->parseConfiguration();
            m_configuration = p_config->getConfiguration();
        }
    }
    return m_configuration;
}
