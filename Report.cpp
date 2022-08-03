#include "Report.h"
#include<iostream>

Report::Report()
{
	report_map.clear();
}
Report::~Report()
{

}
void Report::CreateReport(std::string output, std::string mapIndex)
{
	if (!output.empty())
	{
		report_map[mapIndex].failed_tests++;
	}
	else
	{
		report_map[mapIndex].pass_tests++;
	}
}

std::map<std::string, REPORT>* Report::getReport()
{
	return &report_map;
}

void Report::PrintReport()
{
	std::map<std::string, REPORT>::const_iterator it = report_map.begin();
	for (; it != report_map.end(); it++)
	{
		std::cout << "\n\n------------------------------------REPORT------------------------------------------------\n\n";
		std::cout << "                FileName : " << it->first.substr(0, it->first.find("_")) << "\n";
		std::cout << "                Mutants count : " << it->second.mutants_count << "\n";
		std::cout << "                failed_tests : " << it->second.failed_tests << "\n";
		std::cout << "                passed_tests : " << it->second.pass_tests << "\n";
		std::cout << "                Mutant type : " << to_String(it->second.mutant_type)<< "\n";
		std::vector<std::string>::const_iterator it_vec = it->second.lines.begin();

		for (; it_vec != it->second.lines.end(); it_vec++)
		{
			std::cout << "                Line : " << *it_vec << "\n";
		}

		std::cout << "\n\n------------------------------------END-------------------------------------------------\n\n";
	}

}

std::string Report::to_String(OPERATION_TYPE mutant_type)
{
	switch (mutant_type)
	{
	case INTEGER:
		return "INTEGER";
		break;

	case INSERT:
		return "INSERT";
		break;

	default:
		return "NONE";
		break;
	}
}