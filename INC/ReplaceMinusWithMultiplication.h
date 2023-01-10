#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceMinusWithMultiplication : public MutateOperation
{
	ReplaceMinusWithMultiplication();
	~ReplaceMinusWithMultiplication();
	ReplaceMinusWithMultiplication(const ReplaceMinusWithMultiplication& obj) = delete;
	ReplaceMinusWithMultiplication& operator = (const ReplaceMinusWithMultiplication& obj) = delete;

	static ReplaceMinusWithMultiplication* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceMinusWithMultiplication* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMinusWithMultiplication();
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

