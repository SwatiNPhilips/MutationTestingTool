#pragma once
#include "MutateOperation.h"

class ReplaceAddition : public MutateOperation
{
	ReplaceAddition();
	~ReplaceAddition();
	ReplaceAddition(const ReplaceAddition& obj) = delete;
	ReplaceAddition& operator = (const ReplaceAddition& obj) = delete;

	static ReplaceAddition* m_Instance;
public:

	virtual bool Mutate(string& s) override;

	static ReplaceAddition* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceAddition();
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

