#include "MutateManager.h"
#include "MutateOperationFactory.h"
#include <signal.h>

MutateManager* MutateManager::m_staticObj = nullptr;

MutateManager::MutateManager()
{
    m_configurations.clear();
    mp_FileOp.reset();
    mp_MutateOp = nullptr;

#ifndef _WIN32 
    signal(SIGTSTP, MutateManager::signal_handling);
    signal(SIGHUP, MutateManager::signal_handling);
#else
    signal(SIGBREAK, MutateManager::signal_handling);
#endif
    signal(SIGTERM, MutateManager::signal_handling);
    signal(SIGINT, MutateManager::signal_handling);
    signal(SIGABRT, MutateManager::signal_handling);
}

MutateManager::~MutateManager()
{
    m_configurations.clear();
    mp_FileOp.reset();
    mp_MutateOp = nullptr;
}

void MutateManager::setConfiguration(const CONFIGURATION conf)
{
    m_configurations = conf;
}

void MutateManager::initMutate()
{
    if (boost::filesystem::exists(m_configurations.command.build_path))
    {
        if (!boost::filesystem::exists(m_configurations.command.run_path))
        {
            cout<<endl<<" *** Run path is not valid *** "<<endl;
            return;
        }
    }
    else
    {
        cout<<endl<<" *** Build path is not valid *** "<<endl;
        return;
    }
    try
    {
        if (!m_configurations.config_list.empty())
        {
            m_Exec.setExecuteDetails(m_configurations.command);
            vector<CONFIG_STRUCT>::const_iterator it = m_configurations.config_list.begin();
            for (; it != m_configurations.config_list.end(); it++)
            {
                CONFIG_STRUCT configStruct = *it;
                fs::path full_path = configStruct.file_path / configStruct.file_name;
                if(!fs::exists(full_path))
                {
                    cout<<endl<<" *** File path is not valid *** "<<endl;
                    continue;
                }
                shared_ptr<MutateOperationFactory> mp_factory(make_shared<MutateOperationFactory>());
                mp_FileOp = make_shared<FileOperation>(configStruct.file_name, configStruct.file_path); // new fileop for each file 
                
                if (mp_FileOp != nullptr && mp_factory != nullptr)
                {
                    if (!mp_FileOp->createDB_Folder())
                    {
                        cout<<endl<<"create backup failed. Aborting mutation for this configuration"<<endl;
                        continue;
                    }
                    mp_FileOp->copyOriginalFile();
                    mp_factory->SetOperationType(configStruct.op_type);
                    mp_MutateOp = mp_factory->getOperationType();
                    performMutationTesting(configStruct.op_type);
                }
            }
            printReport();
        }
    }
    catch (exception const& ex)
    {
        cout << endl << ex.what() << endl;
        performActionOnInterrupt();
    }
}

void MutateManager::performMutationTesting(const OPERATION_TYPE type)
{
    cout << "\n\nPerformMutationTesting\n";
    cout << "\n--------------------------\n";

    map<string, REPORT>* p_Report = m_Report.getReport();

    REPORT report;
    report.mutant_type = type;
    string mapIndex = mp_FileOp->getFileName() + "_" + to_string(type);
    (*p_Report)[mapIndex] = report;


    int cnt = mp_FileOp->getLinesCount();
    for (int line = 1; line <= cnt; line++)
    {

        if (mp_FileOp->file_Read(mp_MutateOp, p_Report, mapIndex))
        {
            m_Exec.buildCode();
            m_Report.createReport(m_Exec.runCode(), mapIndex);
            mp_FileOp->replaceOriginalFile();
        }
    }
    mp_FileOp->removeDB_Folder();
}

void MutateManager::printReport()
{
    m_Report.printReport();
}

void MutateManager::performActionOnInterrupt()
{
    if (mp_FileOp != nullptr)
    {
        mp_FileOp->performActionOnInterrupt();
    }
}

void MutateManager::assign_object(void* pObject)
{
    m_staticObj = static_cast<MutateManager*>(pObject);
}


void MutateManager::signal_handling(int signum)
{
    cout << endl << "signal caught " << signum << endl;
    if (m_staticObj != nullptr)
    {
        m_staticObj->performActionOnInterrupt();
    }
    exit(0);
}