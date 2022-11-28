#pragma once
#pragma once
#include <string>
#include"MutateOperation.h"
using namespace std;


class ReplaceInsertWithIndex : public MutateOperation
{
public:
	ReplaceInsertWithIndex();
    ~ReplaceInsertWithIndex();
	ReplaceInsertWithIndex(const ReplaceInsertWithIndex& obj) = delete;
	ReplaceInsertWithIndex& operator = (const ReplaceInsertWithIndex& obj) = delete;
	static ReplaceInsertWithIndex* m_Instance;

public:
	virtual bool Mutate(std::string& s) override;

	static ReplaceInsertWithIndex* GetInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new ReplaceInsertWithIndex();
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

