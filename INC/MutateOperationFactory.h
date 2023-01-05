#pragma once
#include "MutateOperation.h"
#include "MiscEnums.h"
#include <string>
#include<iostream>
#include "ReplaceIntegers.h"
#include "ReplaceInsertWithIndex.h"
#include "ReplaceBoolean.h"
#include "ReplaceEquals.h"

using namespace std;

class MutateOperationFactory
{
	OPERATION_TYPE m_opType;
	void ReleaseInstances();
public:
	MutateOperationFactory();
	~MutateOperationFactory();

	MutateOperation* getOperationType() const;
	void SetOperationType(OPERATION_TYPE type);
};
