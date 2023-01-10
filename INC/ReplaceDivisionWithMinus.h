#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceDivisionWithMinus : public MutateOperation
{
	ReplaceDivisionWithMinus();
	~ReplaceDivisionWithMinus();
	ReplaceDivisionWithMinus(const ReplaceDivisionWithMinus& obj) = delete;
	ReplaceDivisionWithMinus& operator = (const ReplaceDivisionWithMinus& obj) = delete;

	static ReplaceDivisionWithMinus* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceDivisionWithMinus* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceDivisionWithMinus();
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

