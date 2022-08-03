#pragma once
#include<string>
#include "FileOperation.h"
#include"MiscEnums.h"

using namespace std;
class ConfigurationFile
{
	FileOperation* fileOps;
public:

	ConfigurationFile();
	~ConfigurationFile();

	vector<CONFIG_STRUCT> PopulateConfigStruct();
};