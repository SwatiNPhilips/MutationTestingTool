#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceDivisionWithMultiplication : public MutateOperation
{
	ReplaceDivisionWithMultiplication();
	~ReplaceDivisionWithMultiplication();
	ReplaceDivisionWithMultiplication(const ReplaceDivisionWithMultiplication& obj) = delete;
	ReplaceDivisionWithMultiplication& operator = (const ReplaceDivisionWithMultiplication& obj) = delete;

	static ReplaceDivisionWithMultiplication* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceDivisionWithMultiplication* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceDivisionWithMultiplication();
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

