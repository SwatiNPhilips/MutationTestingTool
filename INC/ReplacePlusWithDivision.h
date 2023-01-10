#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplacePlusWithDivision : public MutateOperation
{
	ReplacePlusWithDivision();
	~ReplacePlusWithDivision();
	ReplacePlusWithDivision(const ReplacePlusWithDivision& obj) = delete;
	ReplacePlusWithDivision& operator = (const ReplacePlusWithDivision& obj) = delete;

	static ReplacePlusWithDivision* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplacePlusWithDivision* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplacePlusWithDivision();
		}
		return m_Instance;
	}

	static void ReleaseInstance()
	{
		if (m_Instance != nullptr)
		{
			delete m_Instance;
			m_Instance = nullptr;
		}
	}
};

