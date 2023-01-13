#include "MutateOperationFactory.h"

MutateOperationFactory::MutateOperationFactory()
{
    m_opType = OPERATION_TYPE::NONE;
}

MutateOperationFactory::~MutateOperationFactory()
{
    m_opType = OPERATION_TYPE::NONE;
}

void MutateOperationFactory::SetOperationType(const OPERATION_TYPE type)
{
    m_opType = type;
}

MutateOperation* MutateOperationFactory::getOperationType() const
{
    MutateOperation* operation = nullptr;
    switch (m_opType)
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

    default:
        break;

    }
    return operation;
}
