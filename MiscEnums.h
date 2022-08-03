#pragma once
#include<string>
;

typedef enum
{
	INTEGER = 0,
	INSERT,
	NONE

}OPERATION_TYPE;

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