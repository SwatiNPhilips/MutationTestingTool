#pragma once
#include "MutateOperation.h"
#include "MiscEnums.h"
#include "ReplaceIntegers.h"
#include "ReplaceInsertWithIndex.h"
#include "ReplaceBoolean.h"
#include "ReplaceEquals.h"

class MutateOperationFactory
{
	OPERATION_TYPE m_opType;
	void ReleaseInstances() const;
public:
	MutateOperationFactory();
	~MutateOperationFactory();

	MutateOperation* getOperationType() const;
	void SetOperationType(const OPERATION_TYPE type);
};
