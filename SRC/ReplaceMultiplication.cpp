#include "ReplaceMultiplication.h"
ReplaceMultiplication* ReplaceMultiplication::m_Instance = nullptr;

static constexpr char PLUS_OP[] = " + ";
static constexpr char MULTIPY_OP[] = " * ";

ReplaceMultiplication::ReplaceMultiplication()
{

}

ReplaceMultiplication::~ReplaceMultiplication()
{

}

bool ReplaceMultiplication::Mutate(string& line)
{
	bool result = false;
	cout << "\n ReplaceMultiplication : " << line << "\n";

	size_t pos = 0;
	while((pos = line.find(MULTIPY_OP, pos)) != string::npos)
	{
		line.replace(pos, sizeof(MULTIPY_OP) - 1, PLUS_OP);
		pos += sizeof(PLUS_OP) - 1;
		result = true;
	}

	return result;
}
