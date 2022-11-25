#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceIntegers : public MutateOperation
{
	ReplaceIntegers();
	~ReplaceIntegers();
	ReplaceIntegers(const ReplaceIntegers& obj) = delete;
	ReplaceIntegers& operator = (const ReplaceIntegers& obj) = delete;

	static ReplaceIntegers* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceIntegers* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceIntegers();
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

