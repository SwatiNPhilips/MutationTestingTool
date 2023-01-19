#pragma once
#include "MiscEnums.h"

class MutateOperation
{
public:
    MutateOperation();
    virtual ~MutateOperation();
    MutateOperation(const MutateOperation& obj) = delete;
    MutateOperation& operator = (const MutateOperation& obj) = delete;
    virtual bool Mutate(string& s) = 0;

};
