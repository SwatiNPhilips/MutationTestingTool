#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceMultiplicationWithPlus : public MutateOperation
{
	ReplaceMultiplicationWithPlus();
	~ReplaceMultiplicationWithPlus();
	ReplaceMultiplicationWithPlus(const ReplaceMultiplicationWithPlus& obj) = delete;
	ReplaceMultiplicationWithPlus& operator = (const ReplaceMultiplicationWithPlus& obj) = delete;

	static ReplaceMultiplicationWithPlus* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceMultiplicationWithPlus* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMultiplicationWithPlus();
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

