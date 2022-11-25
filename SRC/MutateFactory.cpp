#include "MutateFactory.h"
#include"MiscEnums.h"
#include"Report.h"

MutateFactory::MutateFactory()
{
	configVec.clear();
	mp_FileOp = nullptr;
	mp_MutateOp = nullptr;
}

MutateFactory::~MutateFactory()
{
	configVec.clear();
	mp_FileOp = nullptr;
	mp_MutateOp = nullptr;
}

void MutateFactory::setConfiguration(vector<CONFIG_STRUCT> conf)
{
	configVec = conf;
}

void MutateFactory::PerformMutationTesting(OPERATION_TYPE type)
{
	cout << "\n\nPerformMutationTesting\n";
	cout << "\n--------------------------\n";

	std::map<std::string, REPORT>* p_Report = m_Report.getReport();
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
			m_Exec.buildCode();
			m_Report.CreateReport(m_Exec.runCode(), mapIndex);
      
			/*MAP_CMD_OP map_cmd_op = m_Exec.runCode(CMD_OP_TYPE::FAILED);
			if (map_cmd_op[CMD_OP_TYPE::FAILED].empty())
			{
				map_cmd_op = m_Exec.runCode(CMD_OP_TYPE::PASSED);
			}

			m_Report.CreateReport(map_cmd_op, mapIndex);*/
      
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

void MutateFactory::printReport()
{
	m_Report.printReport();
}