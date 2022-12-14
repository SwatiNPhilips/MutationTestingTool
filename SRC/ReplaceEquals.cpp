#include "ReplaceEquals.h"

ReplaceEquals* ReplaceEquals::m_Instance = nullptr;

static constexpr char STREQUALS[] = "==";
static constexpr char STRNOTEQUALS[] = "!=";
static constexpr int SIZEOFEQUALS = 2;

ReplaceEquals::ReplaceEquals()
{

}

ReplaceEquals::~ReplaceEquals()
{

}

bool ReplaceEquals::Mutate(std::string& line)
{
	bool result = false;

	cout << "\n ReplaceEquals : " << line << "\n";
	if (line.find("::hl7") != string::npos)
	{
		return  result;
	}
	if ((line.find(STREQUALS) != string::npos))
	{
		line.replace(line.find(STREQUALS), SIZEOFEQUALS, STRNOTEQUALS);
		result = true;
	}
	else if ((line.find(STRNOTEQUALS) != string::npos))
	{
		line.replace(line.find(STRNOTEQUALS), SIZEOFEQUALS, STREQUALS);
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}
