#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceMinusWithPlus : public MutateOperation
{
	ReplaceMinusWithPlus();
	~ReplaceMinusWithPlus();
	ReplaceMinusWithPlus(const ReplaceMinusWithPlus& obj) = delete;
	ReplaceMinusWithPlus& operator = (const ReplaceMinusWithPlus& obj) = delete;

	static ReplaceMinusWithPlus* m_Instance;
public:

	virtual bool Mutate(std::string& s) override;

	static ReplaceMinusWithPlus* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceMinusWithPlus();
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

