#include "ReplaceBoolean.h"

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

bool ReplaceBoolean::Mutate(string& line)
{
    bool result = false;

    cout << "\n replace boolean : " << line << "\n";
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
