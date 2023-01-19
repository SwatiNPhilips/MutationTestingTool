#pragma once
#include "MutateOperation.h"


class ReplaceInsertWithIndex : public MutateOperation
{
    ReplaceInsertWithIndex();
    ~ReplaceInsertWithIndex();
    ReplaceInsertWithIndex(const ReplaceInsertWithIndex& obj) = delete;
    ReplaceInsertWithIndex& operator = (const ReplaceInsertWithIndex& obj) = delete;

public:

    virtual bool Mutate(string& line) override;

    static ReplaceInsertWithIndex* GetInstance()
    {
        static ReplaceInsertWithIndex obj;
        return &obj;
    }
};

