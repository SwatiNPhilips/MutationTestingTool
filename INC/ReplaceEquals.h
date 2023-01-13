#pragma once
#include "MutateOperation.h"

class ReplaceEquals : public MutateOperation
{
    ReplaceEquals();
    ~ReplaceEquals();
    ReplaceEquals(const ReplaceEquals& obj) = delete;
    ReplaceEquals& operator = (const ReplaceEquals& obj) = delete;

public:

    virtual bool Mutate(string& line) override;

    static ReplaceEquals* GetInstance()
    {
        static ReplaceEquals obj;
        return &obj;
    }
};


