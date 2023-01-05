#include <string>
#include<iostream>
#include "Execute.h"
static constexpr char CD[] = "cd";
static constexpr char SPACE[] = " ";
static constexpr char PIPE[] = "|";
static constexpr char GREPFAIL[] = "grep \"FAILED\"";
static constexpr char GREPPASS[] = "grep \"PASSED\"";
static constexpr char SEMICOLON[] = ";";

ExecuteClass::ExecuteClass()
{
	resetDetails();
}

ExecuteClass::~ExecuteClass()
{
	resetDetails();
}

void ExecuteClass::resetDetails()
{
	m_buildPath.clear();
	m_buildCommand.clear();
	m_runPath.clear();
	m_runCommand.clear();
}

void ExecuteClass::setExecuteDetails(CONFIGURATION conf)
{
	m_buildPath = conf.build_path;
	m_buildCommand = conf.build_command;
	m_runPath = conf.run_path;
	m_runCommand = conf.run_command;
}

void ExecuteClass::buildCode()
{
	string cmd = CD + string(SPACE) +  m_buildPath + SEMICOLON + m_buildCommand;
	system(cmd.c_str());

}

std::string ExecuteClass::readConsole(std::string command)
{
	char buffer[128];
	string result = "";
	result.clear();
	FILE* pipe = popen(command.c_str(), "r");

	if (!pipe) {
		cout << "popen failed!" << endl;
	}
	//// read till end of process:
	while (!feof(pipe)) {

		//	// use buffer to read and add to result
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}

	pclose(pipe);
	cout << "\n\n result :" << result;
	return result;
}

MAP_CMD_OP ExecuteClass::runCode()
{
	MAP_CMD_OP map_Cmd_Op;
	map_Cmd_Op[CMD_OP_TYPE::PASSED].clear();
	map_Cmd_Op[CMD_OP_TYPE::FAILED].clear();

	cout << "\n Called runCode" ;
	string cmd = CD + string(SPACE) +  m_runPath + SEMICOLON + m_runCommand + SPACE + PIPE + SPACE + GREPFAIL;
	
	string result = "";
	result = readConsole(cmd);
	if (!result.empty())
	{
		map_Cmd_Op[CMD_OP_TYPE::FAILED] = result;
	}
	else
	{
		cmd.clear();
		cmd = CD + string(SPACE) + m_runPath + SEMICOLON + m_runCommand + SPACE + PIPE + SPACE + GREPPASS;
		result = readConsole(cmd);
		if (!result.empty())
		{
			map_Cmd_Op[CMD_OP_TYPE::PASSED] = result;
		}
	}
	return map_Cmd_Op;
}