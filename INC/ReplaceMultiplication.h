#pragma once
#include "MutateOperation.h"

class ReplaceMultiplication : public MutateOperation
{
	ReplaceMultiplication();
	~ReplaceMultiplication();
	ReplaceMultiplication(const ReplaceMultiplication& obj) = delete;
	ReplaceMultiplication& operator = (const ReplaceMultiplication& obj) = delete;

	static ReplaceMultiplication* m_Instance;
public:

	virtual bool Mutate(string& s) override;

	static ReplaceMultiplication* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMultiplication();
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

