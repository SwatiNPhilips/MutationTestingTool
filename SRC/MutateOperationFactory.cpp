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

	case INCREMENT:
		operation = ReplaceIncrement::GetInstance();
		break;

	case DECREMENT:
		operation = ReplaceDecrement::GetInstance();
		break;

	case PLUSTOMINUS:
		operation = ReplacePlusWithMinus::GetInstance();
		break;

	case PLUSTOMULTIPLICATION:
		operation = ReplacePlusWithMultiplication::GetInstance();
		break;

	case PLUSTODIVISION:
		operation = ReplacePlusWithDivision::GetInstance();
		break;

	case MINUSTOPLUS:
		operation = ReplaceMinusWithPlus::GetInstance();
		break;
	
	case MINUSTOMULTIPLICATION:
		operation = ReplaceMinusWithMultiplication::GetInstance();
		break;
	
	case MINUSTODIVISION:
		operation = ReplaceMinusWithDivision::GetInstance();
		break;
	
	case MULTIPLICATIONTOPLUS:
		operation = ReplaceMultiplicationWithPlus::GetInstance();
		break;

	case MULTIPLICATIONTOMINUS:
		operation = ReplaceMultiplicationWithMinus::GetInstance();
		break;

	case MULTIPLICATIONTODIVISION:
		operation = ReplaceMultiplicationWithDivision::GetInstance();
		break;

	case DIVISIONTOPLUS:
		operation = ReplaceDivisionWithPlus::GetInstance();
		break;
	
	case DIVISIONTOMINUS:
		operation = ReplaceDivisionWithMinus::GetInstance();
		break;

	case DIVISIONTOMULTIPLICATION:
		operation = ReplaceDivisionWithMultiplication::GetInstance();
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

	case INCREMENT:
    	ReplaceIncrement::ReleaseInstance();
		break;

	case DECREMENT:
		ReplaceDecrement::ReleaseInstance();
		break;

	case PLUSTOMINUS:
		ReplacePlusWithMinus::ReleaseInstance();
		break;

	case PLUSTOMULTIPLICATION:
		ReplacePlusWithMultiplication::ReleaseInstance();
		break;
	
	case PLUSTODIVISION:
		ReplacePlusWithDivision::ReleaseInstance();
		break;

	case MINUSTOPLUS:
		ReplaceMinusWithPlus::ReleaseInstance();
		break;
	
	case MINUSTOMULTIPLICATION:
		ReplaceMinusWithMultiplication::ReleaseInstance();
		break;
	
	case MINUSTODIVISION:
		ReplaceMinusWithDivision::ReleaseInstance();
		break;
	
	case MULTIPLICATIONTOPLUS:
		ReplaceMultiplicationWithPlus::ReleaseInstance();
		break;

	case MULTIPLICATIONTOMINUS:
		ReplaceMultiplicationWithMinus::ReleaseInstance();
		break;

	case MULTIPLICATIONTODIVISION:
		ReplaceMultiplicationWithDivision::ReleaseInstance();
		break;

	case DIVISIONTOPLUS:
		ReplaceDivisionWithPlus::ReleaseInstance();
		break;
	
	case DIVISIONTOMINUS:
		ReplaceDivisionWithMinus::ReleaseInstance();
		break;

	case DIVISIONTOMULTIPLICATION:
		ReplaceDivisionWithMultiplication::ReleaseInstance();
		break;

	default:
		break;

	}
}
