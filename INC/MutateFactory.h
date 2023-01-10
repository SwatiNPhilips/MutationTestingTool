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
	ExecuteClass m_Exec;
	Report m_Report;
	CONFIGURATION configurations;

	void PerformMutationTesting(const OPERATION_TYPE);

public:
	MutateFactory();
	~MutateFactory();

	void initMutate();
	void setConfiguration(const CONFIGURATION);
	void printReport();

};

