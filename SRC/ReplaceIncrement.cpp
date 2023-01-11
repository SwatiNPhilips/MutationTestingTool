#include "ReplaceIncrement.h"
ReplaceIncrement* ReplaceIncrement::m_Instance = nullptr;

static const vector<string> INCREMENT_OP = {"++","+="};
static const vector<string> DECREMENT_OP= {"--","-="};
static constexpr int SIZEOFINCREMENT = 2;

ReplaceIncrement::ReplaceIncrement()
{

}

ReplaceIncrement::~ReplaceIncrement()
{

}

bool ReplaceIncrement::Mutate(string& line)
{
	bool result = false;

	cout << "\n ReplaceIncrement : " << line << "\n";
	if ((line.find(INCREMENT_OP[0].c_str()) != string::npos))
	{
		line.replace(line.find(INCREMENT_OP[0].c_str()), SIZEOFINCREMENT, DECREMENT_OP[0].c_str());
		result = true;
	}
    else if ((line.find(INCREMENT_OP[1].c_str()) != string::npos))
	{
		line.replace(line.find(INCREMENT_OP[1].c_str()), SIZEOFINCREMENT, DECREMENT_OP[1].c_str());
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}
