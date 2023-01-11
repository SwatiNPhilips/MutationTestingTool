#pragma once
#include "MutateOperation.h"

class ReplaceDivision : public MutateOperation
{
	ReplaceDivision();
	~ReplaceDivision();
	ReplaceDivision(const ReplaceDivision& obj) = delete;
	ReplaceDivision& operator = (const ReplaceDivision& obj) = delete;

	static ReplaceDivision* m_Instance;
public:

	virtual bool Mutate(string& s) override;

	static ReplaceDivision* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceDivision();
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

