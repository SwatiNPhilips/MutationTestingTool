#include <string>
#include<iostream>
#include "Execute.h"

using namespace std;


ExecuteClass::ExecuteClass()
{
	cout << "\nCalled Execute class ";
	hl7_path.clear();
	hl7_path = "/workspace/delphi-linuxapp-hl7";
}

ExecuteClass::~ExecuteClass()
{
	hl7_path.clear();
}

void ExecuteClass::buildCode()
{
	cout << "\n Called buildCode ";

	string cmd = "cd " + hl7_path + ";" + "make";
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
	string cmd = "cd " + hl7_path + "/UNITTEST" +";" + "./unittest" + "| grep \"FAILED\"";
	
	string result = "";
	result = readConsole(cmd);
	if (!result.empty())
	{
		map_Cmd_Op[CMD_OP_TYPE::FAILED] = result;
	}
	else
	{
		cmd.clear();
		cmd = "cd " + hl7_path + "/UNITTEST" + ";" + "./unittest" + "| grep \"PASSED\"";
		result = readConsole(cmd);
		if (!result.empty())
		{
			map_Cmd_Op[CMD_OP_TYPE::PASSED] = result;
		}
	}
	return map_Cmd_Op;
}