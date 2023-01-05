#pragma once
#include <string>
#include <map>
#include <vector>
typedef enum
{
	INTEGER = 0,
	INSERT,
	BOOLEAN,
	EQUALS,
	NONE

}OPERATION_TYPE;

typedef enum
{
	PASSED = 0,
	FAILED

}CMD_OP_TYPE;

typedef std::map<CMD_OP_TYPE, std::string> MAP_CMD_OP;

struct config_struct
{
	std::string file_name;
	std::string file_path;
	OPERATION_TYPE op_type;

	config_struct()
	{
		file_name.clear();
		file_path.clear();
		op_type = OPERATION_TYPE::NONE;
	}
};
typedef config_struct CONFIG_STRUCT;

struct configuration
{
	std::string build_path;
	std::string build_command;
	std::string run_path;
	std::string run_command;
	std::vector<CONFIG_STRUCT> config_list;
	configuration()
	{
		clear();
	}
	void clear()
	{
		build_path.clear();
		build_command.clear();
		run_path.clear();
		run_command.clear();
		config_list.clear();
	}
};
typedef configuration CONFIGURATION;