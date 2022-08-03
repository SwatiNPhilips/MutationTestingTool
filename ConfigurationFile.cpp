#include "ConfigurationFile.h"
#include<vector>

ConfigurationFile::ConfigurationFile()
{
	string file_name = "config.txt";
	string file_path = "/home/philips/Repo/Mutate_Factory/MutationTesting";
	fileOps = new FileOperation(file_name, file_path);
}
ConfigurationFile::~ConfigurationFile()
{
	if (fileOps != nullptr)
	{
		delete fileOps;
		fileOps = nullptr;
	}
}

vector<CONFIG_STRUCT> ConfigurationFile::PopulateConfigStruct()
{
	vector<CONFIG_STRUCT> configVec;
	vector<string> configVal = fileOps->Read_Config();
	configVec.clear();
	if (!configVal.empty())
	{
		vector<string>::const_iterator it = configVal.begin();
		for (; it != configVal.end(); it++)
		{
			size_t start;
			size_t end = 0;
			string line = *it;
			CONFIG_STRUCT config;

			if ((start = line.find_first_not_of(";", end)) != std::string::npos)
			{
				end = line.find(";", start);
				config.file_name = line.substr(start, end - start);
				if ((start = line.find_first_not_of(";", end)) != std::string::npos)
				{
					end = line.find(";", start);
					config.file_path = line.substr(start, end - start);
					if ((start = line.find_first_not_of(";", end)) != std::string::npos)
					{
						end = line.find(";", start);
						config.op_type = static_cast<OPERATION_TYPE>(atoi(line.substr(start, end - start).c_str()));
					}
				}
			}
			configVec.push_back(config);
		}
	}
	return configVec;
}