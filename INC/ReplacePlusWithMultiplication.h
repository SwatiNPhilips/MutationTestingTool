#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplacePlusWithMultiplication : public MutateOperation
{
	ReplacePlusWithMultiplication();
	~ReplacePlusWithMultiplication();
	ReplacePlusWithMultiplication(const ReplacePlusWithMultiplication& obj) = delete;
	ReplacePlusWithMultiplication& operator = (const ReplacePlusWithMultiplication& obj) = delete;

	static ReplacePlusWithMultiplication* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplacePlusWithMultiplication* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplacePlusWithMultiplication();
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

