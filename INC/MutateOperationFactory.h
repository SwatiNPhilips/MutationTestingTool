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
#include "ReplacePlusWithMinus.h"
#include "ReplacePlusWithMultiplication.h"
#include "ReplacePlusWithDivision.h"
#include "ReplaceMinusWithPlus.h"
#include "ReplaceMinusWithMultiplication.h"
#include "ReplaceMinusWithDivision.h"
#include "ReplaceMultiplicationWithPlus.h"
#include "ReplaceMultiplicationWithMinus.h"
#include "ReplaceMultiplicationWithDivision.h"
#include "ReplaceDivisionWithPlus.h"
#include "ReplaceDivisionWithMinus.h"
#include "ReplaceDivisionWithMultiplication.h"
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
