#include "MutateFactory.h"
#include"MiscEnums.h"
#include"Report.h"

MutateFactory::MutateFactory()
{
	configurations.clear();
	mp_FileOp = nullptr;
	mp_MutateOp = nullptr;
}

MutateFactory::~MutateFactory()
{
	configurations.clear();
	mp_FileOp = nullptr;
	mp_MutateOp = nullptr;
}

void MutateFactory::setConfiguration(const CONFIGURATION conf)
{
	configurations = conf;
}

void MutateFactory::initMutate()
{
	if (! configurations.config_list.empty())
	{
		vector<CONFIG_STRUCT>::const_iterator it = configurations.config_list.begin();
		for (; it != configurations.config_list.end(); it++)
		{
			CONFIG_STRUCT configStruct = *it;

			MutateOperationFactory* mp_factory = new MutateOperationFactory();

			mp_FileOp = new FileOperation(configStruct.file_name , configStruct.file_path); // new fileop for each file 
			if (mp_FileOp != nullptr && mp_factory != nullptr)
			{
				mp_FileOp->init();
				mp_factory->SetOperationType(configStruct.op_type);
				mp_MutateOp = mp_factory->getOperationType();
				PerformMutationTesting(configStruct.op_type);

				delete mp_FileOp; mp_FileOp = nullptr;
				delete mp_factory;mp_factory = nullptr;
			}
		}
	}
}

void MutateFactory::PerformMutationTesting(const OPERATION_TYPE type)
{
	cout << "\n\nPerformMutationTesting\n";
	cout << "\n--------------------------\n";

	map<string, REPORT>* p_Report = m_Report.getReport();
	REPORT report;
	report.mutant_type = type;
	string mapIndex = mp_FileOp->GetFileName() + "_" + to_string(type);
	(*p_Report)[mapIndex] = report;
	m_Exec.setExecuteDetails(configurations);


	int cnt = mp_FileOp->getLinesCount();
	for (int line = 1; line <= cnt; line++)
	{
		if (mp_FileOp->File_Read(mp_MutateOp, p_Report, mapIndex))
		{
			m_Exec.buildCode();
			m_Report.CreateReport(m_Exec.runCode(), mapIndex);    
			mp_FileOp->ReplaceOriginalFile();
		}
	}
}

void MutateFactory::printReport()
{
	m_Report.printReport();
}