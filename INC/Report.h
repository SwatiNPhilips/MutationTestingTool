#pragma once
#include "MiscEnums.h"

struct report_struct
{
    unsigned int mutants_count;
    unsigned int pass_tests;
    unsigned int failed_tests;
    OPERATION_TYPE mutant_type;
    vector<string> lines;
    vector<string> survived_mutants;

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
    map<string,REPORT> report_map;

    string to_String(const OPERATION_TYPE mutant_type) const;
public:
    Report();
    ~Report();
    Report(const Report& obj) = delete;
    Report& operator = (const Report& obj) = delete;

    void createReport(MAP_CMD_OP map_Output, const string mapIndex);
    map<string, REPORT>* getReport();
    void printReport() const;
};

