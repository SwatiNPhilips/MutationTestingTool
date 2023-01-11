#include "ReplaceDivision.h"
ReplaceDivision* ReplaceDivision::m_Instance = nullptr;

static constexpr char DIVIDE_OP[] = " / ";
static constexpr char MINUS_OP[] = " - ";
static constexpr char QUOTE = '\"';

ReplaceDivision::ReplaceDivision()
{

}

ReplaceDivision::~ReplaceDivision()
{

}

bool ReplaceDivision::Mutate(string& line)
{
	bool result = false;
	cout << "\n ReplaceDivision : " << line << "\n";
    
    if(line.find(QUOTE) != string::npos) return false;
    
    size_t pos = 0;
    while((pos = line.find(DIVIDE_OP, pos)) != string::npos)
    {
        line.replace(pos, sizeof(DIVIDE_OP) - 1, MINUS_OP);
        pos += sizeof(MINUS_OP) - 1;
        result = true;
    }

   return result;
}
