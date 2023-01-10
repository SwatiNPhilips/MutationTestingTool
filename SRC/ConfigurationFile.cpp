#include "ConfigurationFile.h"
static constexpr char CONFIGURATIONFILE[] = "configuration.json";

ConfigurationFile::ConfigurationFile()
{

}
ConfigurationFile::~ConfigurationFile()
{

}

CONFIGURATION ConfigurationFile::PopulateConfigStruct()
{
	ConfigurationParser parser(CONFIGURATIONFILE);
	parser.parseConfiguration();

	return parser.getConfiguration();
}