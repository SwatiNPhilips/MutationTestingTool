#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceMultiplicationWithMinus : public MutateOperation
{
	ReplaceMultiplicationWithMinus();
	~ReplaceMultiplicationWithMinus();
	ReplaceMultiplicationWithMinus(const ReplaceMultiplicationWithMinus& obj) = delete;
	ReplaceMultiplicationWithMinus& operator = (const ReplaceMultiplicationWithMinus& obj) = delete;

	static ReplaceMultiplicationWithMinus* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceMultiplicationWithMinus* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMultiplicationWithMinus();
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

