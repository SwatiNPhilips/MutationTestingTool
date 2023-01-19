#pragma once
#include "MutateOperation.h"

class ReplaceBoolean : public MutateOperation
{
    ReplaceBoolean();
    ~ReplaceBoolean();
    ReplaceBoolean(const ReplaceBoolean& obj) = delete;
    ReplaceBoolean& operator = (const ReplaceBoolean& obj) = delete;

public:

    virtual bool Mutate(string& line) override;

    static ReplaceBoolean* GetInstance()
    {
        static ReplaceBoolean obj;
        return &obj;
    }
};

