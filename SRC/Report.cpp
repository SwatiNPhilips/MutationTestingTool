#include "Report.h"

Report::Report()
{
	report_map.clear();
}
Report::~Report()
{
	report_map.clear();

}
void Report::CreateReport(MAP_CMD_OP map_Output, const string mapIndex)
{
	if (map_Output[CMD_OP_TYPE::FAILED].empty() && map_Output[CMD_OP_TYPE::PASSED].empty())
	{
	    report_map[mapIndex].failed_tests++;
	}

  else if (!map_Output[CMD_OP_TYPE::FAILED].empty())
	{
		report_map[mapIndex].failed_tests++;
	}
	else if(!map_Output[CMD_OP_TYPE::PASSED].empty())
	{
		report_map[mapIndex].pass_tests++;
    	report_map[mapIndex].survived_mutants.push_back(report_map[mapIndex].lines.back());
	}
}

map<string, REPORT>* Report::getReport()
{
	return &report_map;
}

void Report::printReport() const 
{
	map<string, REPORT>::const_iterator it = report_map.begin();
	for (; it != report_map.end(); it++)
	{
		cout << "\n\n------------------------------------REPORT------------------------------------------\n\n";
		cout << "                FileName : " << it->first.substr(0, it->first.find("_")) << "\n";
		cout << "                Mutants count : " << it->second.mutants_count << "\n";
		cout << "                failed_tests : " << it->second.failed_tests << "\n";
		cout << "                passed_tests : " << it->second.pass_tests << "\n";
		cout << "                Mutant type : " << to_String(it->second.mutant_type)<< "\n";
		vector<string>::const_iterator it_vec = it->second.survived_mutants.begin();

    	cout << "\n\n\n\n";
    	cout << "                   ******* Survived Mutants *********"<<"\n";
		for (; it_vec != it->second.survived_mutants.end(); it_vec++)
		{
			cout << "                Line : " << *it_vec << "\n";
		}
   
    	cout << "\n\n\n\n";
 		it_vec = it->second.lines.begin();
    	cout << "                   ******* Changed Lines *********"<<"\n";
		for (; it_vec != it->second.lines.end(); it_vec++)
		{
			cout << "                Line : " << *it_vec << "\n";
		}

		cout << "\n\n------------------------------------END--------------------------------------------\n\n";
	}

}

string Report::to_String(const OPERATION_TYPE mutant_type) const
{
	switch (mutant_type)
	{
	case INTEGER:
		return "INTEGER";
		break;

	case INSERT:
		return "INSERT";
		break;

	case BOOLEAN:
		return "BOOLEAN";
		break;

	case EQUALS:
		return "EQUALS";
		break;

	default:
		return "NONE";
		break;
	}
}
