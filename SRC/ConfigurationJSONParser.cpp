#include "ConfigurationJSONParser.h"

namespace pt = boost::property_tree;

static constexpr char CONFIGURATIONFILE[] = "configuration.json";

ConfigurationJSONParser::ConfigurationJSONParser():ConfigurationOperation()
{

}
ConfigurationJSONParser::~ConfigurationJSONParser()
{

}

void ConfigurationJSONParser::parseConfiguration()
{  
    pt::ptree node;
    try
    {
        pt::read_json(CONFIGURATIONFILE, node);  

        m_configuration.command.build_command = node.get<string>("Commands.Build.command");
        m_configuration.command.build_path = node.get<fs::path>("Commands.Build.path");
        m_configuration.command.run_command = node.get<string>("Commands.Run.command");
        m_configuration.command.run_path = node.get<fs::path>("Commands.Run.path"); 

        for (pt::ptree::value_type & childs : node.get_child("FileDetails"))
        {
            CONFIG_STRUCT configStruct;
            configStruct.file_name = childs.second.get<fs::path>("name");
            configStruct.file_path = childs.second.get<fs::path>("path");
            configStruct.op_type = static_cast<OPERATION_TYPE>(childs.second.get<int>("operation"));
            m_configuration.config_list.emplace_back(configStruct);
        }
    }
    catch(boost::exception const& ex)
    {
        cout<<endl<<boost::diagnostic_information(ex)<<endl;;
    }
}
