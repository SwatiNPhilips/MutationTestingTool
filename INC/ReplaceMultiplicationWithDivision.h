#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceMultiplicationWithDivision : public MutateOperation
{
	ReplaceMultiplicationWithDivision();
	~ReplaceMultiplicationWithDivision();
	ReplaceMultiplicationWithDivision(const ReplaceMultiplicationWithDivision& obj) = delete;
	ReplaceMultiplicationWithDivision& operator = (const ReplaceMultiplicationWithDivision& obj) = delete;

	static ReplaceMultiplicationWithDivision* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceMultiplicationWithDivision* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMultiplicationWithDivision();
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

