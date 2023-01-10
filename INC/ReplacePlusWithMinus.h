#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplacePlusWithMinus : public MutateOperation
{
	ReplacePlusWithMinus();
	~ReplacePlusWithMinus();
	ReplacePlusWithMinus(const ReplacePlusWithMinus& obj) = delete;
	ReplacePlusWithMinus& operator = (const ReplacePlusWithMinus& obj) = delete;

	static ReplacePlusWithMinus* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplacePlusWithMinus* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplacePlusWithMinus();
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

