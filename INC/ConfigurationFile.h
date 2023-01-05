#pragma once
#include<string>
#include "ConfigurationParser.h"
#include"MiscEnums.h"

using namespace std;
class ConfigurationFile
{
public:

	ConfigurationFile();
	~ConfigurationFile();

	CONFIGURATION PopulateConfigStruct();
};