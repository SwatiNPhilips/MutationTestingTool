#include "ReplaceIntegers.h"
#include<string>

ReplaceIntegers* ReplaceIntegers::m_Instance = nullptr;

ReplaceIntegers::ReplaceIntegers()
{
	
}

ReplaceIntegers::~ReplaceIntegers()
{

}

bool ReplaceIntegers::Mutate(std::string& s)
{
	cout << "\n entered Mutate in Replace integers :\n";
	const char* c = s.c_str();
	bool result = false;

	cout << "\n replace number : " << s << "\n";
  if(s.find("::hl7") != string::npos) return  result;
	std::string::const_iterator it = s.begin();
	for (int i = 0; it != s.end(); i++, it++)
	{
		if (std::isdigit(*it))
		{

			int tmp = atoi(&c[i]);
			cout << "\n replace number : " << tmp << "\n";
			if (tmp == 0)
				s[i] = '1';
			else
				s[i] = '0';

			return true;

		}

	}

	return result;
}
