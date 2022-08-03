#include <string>
#include<iostream>
#include "Execute.h"

using namespace std;


ExecuteClass::ExecuteClass()
{
	cout << "\nCalled Execute class ";
	hl7_path = "/home/philips/Repo/delphi-linuxapp-hl7";
}

ExecuteClass::~ExecuteClass()
{

}

void ExecuteClass::buildCode()
{
	cout << "\n Called buildCode ";

	string cmd = "cd " + hl7_path + ";" + "make";
	system(cmd.c_str());

}

std::string ExecuteClass::runCode()
{
	string cmd = "cd " + hl7_path + "/UNITTEST" + +";" + "./unittest" + "| grep \"FAILED TEST\"";
	cout << "\n Called runCode :  " << cmd;
	//system(cmd.c_str());

	char buffer[128];
	string result = "";
	FILE* pipe = popen(cmd.c_str(), "r");

	if (!pipe) {
		cout<<"popen failed!"<<endl;
	}
	//// read till end of process:
	while (!feof(pipe)) {

	//	// use buffer to read and add to result
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}

	pclose(pipe);
  cout <<"\n\n result :"<< result; 
	return result;

}
