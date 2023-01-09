#pragma once
#include "ConfigurationParser.h"
#include"MiscEnums.h"

class ConfigurationFile
{
public:

	ConfigurationFile();
	~ConfigurationFile();

	CONFIGURATION PopulateConfigStruct();
};