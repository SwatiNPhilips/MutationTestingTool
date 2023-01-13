#pragma once
#include "FileOperation.h"
#include "MutateOperation.h"
#include "Execute.h"
#include "Report.h"
#include "MiscEnums.h"


class MutateManager
{
    shared_ptr<FileOperation> mp_FileOp;
    MutateOperation* mp_MutateOp;
    Execute m_Exec;
    Report m_Report;
    CONFIGURATION m_configurations;

    // static member variable for signal handling
    static MutateManager* m_staticObj;

    void performMutationTesting(const OPERATION_TYPE);
    void printReport();

public:
    MutateManager();
    ~MutateManager();

    void initMutate();
    void setConfiguration(const CONFIGURATION);
    void performActionOnInterrupt();

    // static functions for signal handling
    static void signal_handling (int signum);
    static void assign_object (void *pObject);
};

