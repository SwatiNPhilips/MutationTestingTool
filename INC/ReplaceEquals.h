#pragma once
#include "MutateOperation.h"

class ReplaceEquals : public MutateOperation
{
	ReplaceEquals();
	~ReplaceEquals();
	ReplaceEquals(const ReplaceEquals& obj) = delete;
	ReplaceEquals& operator = (const ReplaceEquals& obj) = delete;

	static ReplaceEquals* m_Instance;
public:

	virtual bool Mutate(string& line) override;

	static ReplaceEquals* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceEquals();
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

