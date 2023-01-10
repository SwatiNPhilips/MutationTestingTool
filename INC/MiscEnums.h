#pragma once
#include <string>
#include <map>
#include <vector>
#include<iostream>

using namespace std;
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

typedef map<CMD_OP_TYPE, string> MAP_CMD_OP;

struct config_struct
{
	string file_name;
	string file_path;
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
	string build_path;
	string build_command;
	string run_path;
	string run_command;
	vector<CONFIG_STRUCT> config_list;
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