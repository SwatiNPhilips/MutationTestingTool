#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceDivisionWithPlus : public MutateOperation
{
	ReplaceDivisionWithPlus();
	~ReplaceDivisionWithPlus();
	ReplaceDivisionWithPlus(const ReplaceDivisionWithPlus& obj) = delete;
	ReplaceDivisionWithPlus& operator = (const ReplaceDivisionWithPlus& obj) = delete;

	static ReplaceDivisionWithPlus* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceDivisionWithPlus* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceDivisionWithPlus();
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

