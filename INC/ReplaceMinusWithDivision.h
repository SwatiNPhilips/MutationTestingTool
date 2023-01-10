#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceMinusWithDivision : public MutateOperation
{
	ReplaceMinusWithDivision();
	~ReplaceMinusWithDivision();
	ReplaceMinusWithDivision(const ReplaceMinusWithDivision& obj) = delete;
	ReplaceMinusWithDivision& operator = (const ReplaceMinusWithDivision& obj) = delete;

	static ReplaceMinusWithDivision* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceMinusWithDivision* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMinusWithDivision();
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

