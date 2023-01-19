#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

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
    fs::path file_name;
    fs::path file_path;
    OPERATION_TYPE op_type;

    config_struct()
    {
        file_name.clear();
        file_path.clear();
        op_type = OPERATION_TYPE::NONE;
    }
};
typedef config_struct CONFIG_STRUCT;

struct commands
{
    fs::path build_path;
    string build_command;
    fs::path run_path;
    string run_command;
    commands()
    {
        clear();
    }
    void clear()
    {
        build_path.clear();
        build_command.clear();
        run_path.clear();
        run_command.clear();
    }
};
typedef commands COMMANDS;

struct configuration
{
    COMMANDS command;
    vector<CONFIG_STRUCT> config_list;
    configuration()
    {
        clear();
    }
    void clear()
    {
        command.clear();
        config_list.clear();
    }
};
typedef configuration CONFIGURATION;

typedef enum
{
    JSON = 0,
    DEFAULT
}CONFIGURATION_TYPE;