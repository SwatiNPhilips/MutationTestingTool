#include "MutateManager.h"
#include "ConfigurationManager.h"

int main(int argc, char* argv[])
{
    try
    {
        shared_ptr<ConfigurationManager> p_configManager(make_shared<ConfigurationManager>());
        if (p_configManager != nullptr)
        {
            CONFIGURATION_TYPE config_type = CONFIGURATION_TYPE::JSON;
            shared_ptr<MutateManager> p_mutateManager(make_shared<MutateManager>());
            MutateManager::assign_object(&p_mutateManager);
            p_mutateManager->setConfiguration(p_configManager->PopulateConfigStruct(config_type));
            if (p_mutateManager != nullptr)
            {
                p_mutateManager->initMutate();
            }
        }
    }
    catch(exception const& ex)
    {
        cout<<endl<<ex.what()<<endl;;
    }
}