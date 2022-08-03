#pragma once
#include"FileOperation.h"
#include"MutateOperation.h"
#include"ReplaceIntegers.h"
#include"Execute.h"
#include"Report.h"
#include "MutateOperationFactory.h"

class MutateFactory
{
	FileOperation* mp_FileOp;
	MutateOperation* mp_MutateOp;
	ExecuteClass* mp_exec;
	Report* mp_Report;
	vector<CONFIG_STRUCT> configVec;

	void PerformMutationTesting(OPERATION_TYPE type);

public:
	MutateFactory(vector<CONFIG_STRUCT> conf);
	~MutateFactory();

	void initMutate();
	void PrintReport();

};

