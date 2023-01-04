#include "MutateOperationFactory.h"

MutateOperationFactory::MutateOperationFactory()
{
	opType = OPERATION_TYPE::NONE;
}

MutateOperationFactory::~MutateOperationFactory()
{
	ReleaseInstances();
	opType = OPERATION_TYPE::NONE;
}

void MutateOperationFactory::SetOperationType(OPERATION_TYPE type)
{
	opType = type;
}

MutateOperation* MutateOperationFactory::getOperation()
{
	MutateOperation* operation = nullptr;
	
	switch (opType)
	{
	case INTEGER:
		operation = ReplaceIntegers::GetInstance();
		break;

	case INSERT:
		operation = ReplaceInsertWithIndex::GetInstance();
		break;

	case BOOLEAN:
		operation = ReplaceBoolean::GetInstance();
		break;

	case EQUALS:
		operation = ReplaceEquals::GetInstance();
		break;

	case INCREMENTDECREMENT:
		operation = ReplaceIncrement::GetInstance();
		break;

	default:
		break;
	}

	return operation;
}

void MutateOperationFactory::ReleaseInstances()
{
	switch (opType)
	{
	case INTEGER:
		ReplaceIntegers::ReleaseInstance();
		break;

	case INSERT:
		ReplaceInsertWithIndex::ReleaseInstance();

	case BOOLEAN:
		ReplaceBoolean::ReleaseInstance();
		break;

	case EQUALS:
		ReplaceEquals::ReleaseInstance();
		break;

	case INCREMENTDECREMENT:
    	ReplaceIncrement::ReleaseInstance();
		break;

	default:
		break;

	}
}
