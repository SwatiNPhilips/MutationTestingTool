#pragma once
#include "MutateOperation.h"

class ReplaceIntegers : public MutateOperation
{
    ReplaceIntegers();
    ~ReplaceIntegers();
    ReplaceIntegers(const ReplaceIntegers& obj) = delete;
    ReplaceIntegers& operator = (const ReplaceIntegers& obj) = delete;

public:

    virtual bool Mutate(string& line) override;

    static ReplaceIntegers* GetInstance()
    {
        static ReplaceIntegers obj;
        return &obj;
    }
};