#pragma once
#include "MiscEnums.h"

class ExecuteClass
{
	string  m_buildPath;
	string  m_buildCommand;
	string  m_runPath;
	string  m_runCommand;

	string readConsole(const string) const;
	void resetDetails();
public:
	ExecuteClass();
	~ExecuteClass();

	void setExecuteDetails(const CONFIGURATION);
	void buildCode();
	MAP_CMD_OP runCode();

};

