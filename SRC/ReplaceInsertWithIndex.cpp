#include "ReplaceInsertWithIndex.h"

ReplaceInsertWithIndex::ReplaceInsertWithIndex()
{

}
ReplaceInsertWithIndex::~ReplaceInsertWithIndex()
{

}

bool ReplaceInsertWithIndex::Mutate(string& line)
{
    string strLine(line);
    string strToFind = "HL7Segment::insert(";
    bool result = false;

    if ((strLine.find(strToFind) != string::npos) && (strLine.find(",") != string::npos) && (!(strLine.find("void") != string::npos)))
    {
        auto len_Str = strLine.find(strToFind) + strToFind.length();
        auto len_comma = strLine.find(",");
        string subStrToFind = strLine.substr(len_Str, (len_comma - len_Str));
        const char* c = subStrToFind.c_str();
        string::const_iterator it = subStrToFind.begin();
        for (int i = 0; it != subStrToFind.end(); i++, it++)
        {
            if (isdigit(*it))
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
