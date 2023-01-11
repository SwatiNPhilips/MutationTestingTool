#pragma once
#include "MutateOperation.h"

class ReplaceSubtraction : public MutateOperation
{
	ReplaceSubtraction();
	~ReplaceSubtraction();
	ReplaceSubtraction(const ReplaceSubtraction& obj) = delete;
	ReplaceSubtraction& operator = (const ReplaceSubtraction& obj) = delete;

	static ReplaceSubtraction* m_Instance;
public:

	virtual bool Mutate(string& s) override;

	static ReplaceSubtraction* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceSubtraction();
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

