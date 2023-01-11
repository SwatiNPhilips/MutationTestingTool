#include "ReplaceAddition.h"
ReplaceAddition* ReplaceAddition::m_Instance = nullptr;

static constexpr char PLUS_OP[] = " + ";
static constexpr char MULTIPY_OP[] = " * ";

ReplaceAddition::ReplaceAddition()
{

}

ReplaceAddition::~ReplaceAddition()
{

}

bool ReplaceAddition::Mutate(string& line)
{
	bool result = false;
	cout << "\n ReplaceAddition : " << line << "\n";

	size_t pos = 0;
	while((pos = line.find(PLUS_OP, pos)) != string::npos)
	{
		line.replace(pos, sizeof(PLUS_OP) - 1, MULTIPY_OP);
		pos += sizeof(MULTIPY_OP) - 1;
		result = true;
	}

	return result;
}
