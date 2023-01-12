
#include "ReplaceDecrement.h"
ReplaceDecrement* ReplaceDecrement::m_Instance = nullptr;

static const vector<string> INCREMENT_OP = {"++","+="};
static const vector<string> DECREMENT_OP= {"--","-="};
static constexpr int SIZEOFDECREMENT = 2;

ReplaceDecrement::ReplaceDecrement()
{

}

ReplaceDecrement::~ReplaceDecrement()
{

}

bool ReplaceDecrement::Mutate(string& line)
{
	bool result = false;

	cout << "\n ReplaceDecrement : " << line << "\n";
	if ((line.find(DECREMENT_OP[0].c_str()) != string::npos))
	{
		line.replace(line.find(DECREMENT_OP[0].c_str()), SIZEOFDECREMENT, INCREMENT_OP[0].c_str());
		result = true;
	}
	else if ((line.find(DECREMENT_OP[1].c_str()) != string::npos))
	{
		line.replace(line.find(DECREMENT_OP[1].c_str()), SIZEOFDECREMENT, INCREMENT_OP[1].c_str());
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}
