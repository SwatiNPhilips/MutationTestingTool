#pragma once
#include "MutateOperation.h"
#include<string>
#include<vector>

using namespace std;
class ReplaceDecrement : public MutateOperation
{
	ReplaceDecrement();
	~ReplaceDecrement();
	ReplaceDecrement(const ReplaceDecrement& obj) = delete;
	ReplaceDecrement& operator = (const ReplaceDecrement& obj) = delete;

	static ReplaceDecrement* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceDecrement* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceDecrement();
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

