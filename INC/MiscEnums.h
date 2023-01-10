#pragma once
#include <string>
#include <map>
typedef enum
{
	INTEGER = 0,
	INSERT,
	BOOLEAN,
	EQUALS,
	INCREMENT,
	DECREMENT,
	PLUSTOMINUS,
	PLUSTOMULTIPLICATION,
	PLUSTODIVISION,
	MINUSTOPLUS,
	MINUSTOMULTIPLICATION,
	MINUSTODIVISION,
	MULTIPLICATIONTOPLUS,
	MULTIPLICATIONTOMINUS,
	MULTIPLICATIONTODIVISION,
	DIVISIONTOPLUS,
	DIVISIONTOMINUS,
	DIVISIONTOMULTIPLICATION,
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