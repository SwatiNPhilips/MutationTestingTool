#include "ReplaceBoolean.h"

ReplaceBoolean* ReplaceBoolean::m_Instance = nullptr;

static constexpr int SIZEOFTRUE = 4;
static constexpr int SIZEOFFALSE = 5;
static constexpr char STRTRUE[] = "true";
static constexpr char STRFALSE[] = "false";

ReplaceBoolean::ReplaceBoolean()
{

}

ReplaceBoolean::~ReplaceBoolean()
{

}

bool ReplaceBoolean::Mutate(std::string& line)
{
	const char* c = line.c_str();
	bool result = false;

	cout << "\n replace boolean : " << line << "\n";
	if (line.find("::hl7") != string::npos)
	{
		return  result;
	}
	std::string::const_iterator it = line.begin();
	if ((line.find(" true") != string::npos) || (line.find("(true") != string::npos))
	{
		line.replace(line.find(STRTRUE), SIZEOFTRUE, STRFALSE);
		result = true;
	}
	else if ((line.find(" false") != string::npos) || (line.find("(false") != string::npos))
	{
		line.replace(line.find(STRFALSE), SIZEOFFALSE, STRTRUE);
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}
