#pragma once
#include "MutateOperation.h"
#include "MiscEnums.h"
#include <string>
#include<iostream>
#include "ReplaceIntegers.h"
#include "ReplaceInsertWithIndex.h"
#include "ReplaceBoolean.h"
#include "ReplaceEquals.h"
#include "ReplaceIncrement.h"
#include "ReplaceDecrement.h"
#include "ReplaceAddition.h"
#include "ReplaceSubtraction.h"
#include "ReplaceMultiplication.h"
#include "ReplaceDivision.h"

using namespace std;

class MutateOperationFactory
{
	OPERATION_TYPE opType;
	void ReleaseInstances();
public:
	MutateOperationFactory();
	~MutateOperationFactory();

	MutateOperation* getOperation();
	void SetOperationType(OPERATION_TYPE type);
};
