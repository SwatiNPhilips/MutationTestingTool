#include "ReplaceSubtraction.h"
ReplaceSubtraction* ReplaceSubtraction::m_Instance = nullptr;

static constexpr char PLUS_OP[] = " + ";
static constexpr char MINUS_OP[] = " - ";

ReplaceSubtraction::ReplaceSubtraction()
{

}

ReplaceSubtraction::~ReplaceSubtraction()
{

}

bool ReplaceSubtraction::Mutate(string& line)
{
	bool result = false;
	cout << "\n ReplaceSubtraction : " << line << "\n";

	size_t pos = 0;
	while((pos = line.find(MINUS_OP, pos)) != string::npos)
	{
		line.replace(pos, sizeof(MINUS_OP) - 1, PLUS_OP);
		pos += sizeof(PLUS_OP) - 1;
		result = true;
	}

	return result;
}
