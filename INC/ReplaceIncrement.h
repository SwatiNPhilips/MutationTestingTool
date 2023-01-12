#pragma once
#include "MutateOperation.h"
#include <vector>

class ReplaceIncrement : public MutateOperation
{
	ReplaceIncrement();
	~ReplaceIncrement();
	ReplaceIncrement(const ReplaceIncrement& obj) = delete;
	ReplaceIncrement& operator = (const ReplaceIncrement& obj) = delete;

	static ReplaceIncrement* m_Instance;
public:

	virtual bool Mutate(string& s) override;

	static ReplaceIncrement* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceIncrement();
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

