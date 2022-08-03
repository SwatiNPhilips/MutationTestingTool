#pragma once
#include "MutateOperation.h"
#include<string>

using namespace std;
class ReplaceBoolean : public MutateOperation
{
	ReplaceBoolean();
	~ReplaceBoolean();
	ReplaceBoolean(const ReplaceBoolean& obj) = delete;
	ReplaceBoolean& operator = (const ReplaceBoolean& obj) = delete;

	static ReplaceBoolean* m_Instance;
public:

	virtual bool Mutate(std::string& line) override;

	static ReplaceBoolean* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceBoolean();
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

