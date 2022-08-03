#include "MutateFactory.h"
#include"MiscEnums.h"
#include"Report.h"

MutateFactory::MutateFactory(vector<CONFIG_STRUCT> conf)
{
	configVec.clear();
	mp_FileOp = nullptr;
	mp_MutateOp = nullptr;
	mp_exec = new ExecuteClass();
	mp_Report = new Report();
	configVec = conf;

}

MutateFactory::~MutateFactory()
{

}

void MutateFactory::PerformMutationTesting(OPERATION_TYPE type)
{
	cout << "\n\nPerformMutationTesting\n";
	cout << "\n--------------------------\n";

	std::map<std::string, REPORT>* p_Report = mp_Report->getReport();
	REPORT report;
	report.mutant_type = type;
	string mapIndex = mp_FileOp->GetFileName() + "_" + to_string(type);
	(*p_Report)[mapIndex] = report;


	int cnt = mp_FileOp->getLinesCount();
	cout << "count: " << cnt;
	for (int i = 1; i <= cnt; i++)
	{
		if (mp_FileOp->File_Read(mp_MutateOp, p_Report, mapIndex))
		{
			mp_exec->buildCode();
			mp_Report->CreateReport(mp_exec->runCode(), mapIndex);
			mp_FileOp->ReplaceOriginalFile();
		}
	}
}

void MutateFactory::initMutate()
{
	if (!configVec.empty())
	{
		vector<CONFIG_STRUCT>::const_iterator it = configVec.begin();
		for (; it != configVec.end(); it++)
		{
			CONFIG_STRUCT configStruct = *it;

			MutateOperationFactory* mp_factory = new MutateOperationFactory();

			mp_FileOp = new FileOperation(configStruct.file_name , configStruct.file_path); // new fileop for each file 
			if (mp_FileOp != nullptr && mp_factory != nullptr)
			{
				mp_FileOp->init();
				mp_factory->SetOperationType(configStruct.op_type);
				mp_MutateOp = mp_factory->getOperation();
				PerformMutationTesting(configStruct.op_type);

				delete mp_FileOp; mp_FileOp = nullptr;
				delete mp_factory;mp_factory = nullptr;
			}
		}
	}
}

void MutateFactory::PrintReport()
{
	mp_Report->PrintReport();
}