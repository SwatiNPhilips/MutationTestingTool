#include "ConfigurationParser.h"
namespace pt = boost::property_tree;

ConfigurationParser::ConfigurationParser(string abs_path)
{
	m_abspath = abs_path;
  m_configuration.clear();
}
ConfigurationParser::~ConfigurationParser()
{
  m_abspath.clear();
  m_configuration.clear();
}

void ConfigurationParser::parseConfiguration()
{  
  pt::ptree node;
  pt::read_json(m_abspath, node);  

  m_configuration.build_command = node.get<string>("Commands.Build.command");
  m_configuration.build_path = node.get<string>("Commands.Build.path");
  m_configuration.run_command = node.get<string>("Commands.Run.command");
  m_configuration.run_path = node.get<string>("Commands.Run.path"); 


  for (pt::ptree::value_type & v : node.get_child("FileDetails"))
  {
    int index = 0;
    CONFIG_STRUCT configStruct;
    for (pt::ptree::value_type &cell : v.second)
    {
      if (index == 0)
      {
        configStruct.file_name = cell.second.get_value<string>();
      }
      else if (index == 1)
      {
        configStruct.file_path = cell.second.get_value<string>();
      }
      else if (index == 2)
      {
        configStruct.op_type = static_cast<OPERATION_TYPE>(cell.second.get_value<int>());
      }
      index ++;
    }
    m_configuration.config_list.push_back(configStruct);
  }
}

CONFIGURATION ConfigurationParser::getConfiguration() const
{
 return m_configuration;
}