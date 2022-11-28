#include "ReplaceInsertWithIndex.h"
#include<string>
#include <iostream>

ReplaceInsertWithIndex* ReplaceInsertWithIndex::m_Instance = nullptr;

ReplaceInsertWithIndex::ReplaceInsertWithIndex()
{

}
ReplaceInsertWithIndex::~ReplaceInsertWithIndex()
{

}

bool ReplaceInsertWithIndex::Mutate(std::string& line)
{
	string strLine(line);
	std::string strToFind = "HL7Segment::insert(";
	bool result = false;

	if ((strLine.find(strToFind) != string::npos) && (strLine.find(",") != string::npos) && (!(strLine.find("void") != string::npos)))
	{
		bool flag = false;
		auto len_Str = strLine.find(strToFind) + strToFind.length();
		auto len_comma = strLine.find(",");
		std::string subStrToFind = strLine.substr(len_Str, (len_comma - len_Str));
		const char* c = subStrToFind.c_str();
		std::string::const_iterator it = subStrToFind.begin();
		for (int i = 0; it != subStrToFind.end(); i++, it++)
		{
			if (std::isdigit(*it))
			{

				int tmp = atoi(&c[i]);
				if (tmp == 0)
					subStrToFind[i] = '1';
				else
					subStrToFind[i] = '0';
			}

		}
		line.clear();
		line = strLine.substr(0, len_Str) + subStrToFind;
		result = true;
	}
	return result;
}
