#pragma once
#include<string>
#include<vector>
#include "MiscEnums.h"
#include<map>

struct report_struct
{
	unsigned int mutants_count;
	unsigned int pass_tests;
	unsigned int failed_tests;
	OPERATION_TYPE mutant_type;
	std::vector<std::string> lines;
 	std::vector<std::string> survived_mutants;

	report_struct()
	{
		mutants_count = pass_tests = failed_tests = 0;
		mutant_type = OPERATION_TYPE::NONE;
		lines.clear();
    survived_mutants.clear();
	}
};

typedef report_struct REPORT;


class Report
{
	std::map<std::string,REPORT> report_map;

	std::string to_String(OPERATION_TYPE mutant_type);
public:

	Report();
	~Report();

	void CreateReport(MAP_CMD_OP map_Output, std::string mapIndex);
	std::map<std::string, REPORT>* getReport();
	void printReport();
};

