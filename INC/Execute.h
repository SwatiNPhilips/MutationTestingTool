#pragma once
#include "MiscEnums.h"
using namespace std;

class ExecuteClass
{
	string  m_buildPath;
	string  m_buildCommand;
	string  m_runPath;
	string  m_runCommand;

	string readConsole(std::string command);
public:
	ExecuteClass();
	~ExecuteClass();
	void resetDetails();

	void setExecuteDetails(CONFIGURATION conf);
	void buildCode();
	MAP_CMD_OP runCode();

};

