#pragma once
#include "MiscEnums.h"
class ExecuteClass
{
	std::string  hl7_path;
	std::string readConsole(std::string command);
public:
	ExecuteClass();
	~ExecuteClass();

	void buildCode();
	MAP_CMD_OP runCode();

};

