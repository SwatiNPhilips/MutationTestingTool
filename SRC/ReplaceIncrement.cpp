#include "ReplaceIncrement.h"
ReplaceIncrement* ReplaceIncrement::m_Instance = nullptr;

static const vector<string> INCREMENT = {"++","+="};
static const vector<string> DECREMENT= {"--","-="};
static constexpr int SIZEOFINCREMENT = 2;

ReplaceIncrement::ReplaceIncrement()
{

}

ReplaceIncrement::~ReplaceIncrement()
{

}

bool ReplaceIncrement::Mutate(std::string& line)
{
	const char* c = line.c_str();
	bool result = false;

	cout << "\n ReplaceIncrement : " << line << "\n";
	if (line.find("::hl7") != string::npos)
	{
		return  result;
	}
	std::string::const_iterator it = line.begin();
	if ((line.find(INCREMENT[0].c_str()) != string::npos))
	{
		line.replace(line.find(INCREMENT[0].c_str()), SIZEOFINCREMENT, DECREMENT[0].c_str());
		result = true;
	}
    else if ((line.find(INCREMENT[1].c_str()) != string::npos))
	{
		line.replace(line.find(INCREMENT[1].c_str()), SIZEOFINCREMENT, DECREMENT[1].c_str());
		result = true;
	}
	else if ((line.find(DECREMENT[0].c_str()) != string::npos))
	{
		line.replace(line.find(DECREMENT[0].c_str()), SIZEOFINCREMENT, INCREMENT[0].c_str());
		result = true;
	}
    else if ((line.find(DECREMENT[1].c_str()) != string::npos))
	{
		line.replace(line.find(DECREMENT[1].c_str()), SIZEOFINCREMENT, INCREMENT[1].c_str());
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}
