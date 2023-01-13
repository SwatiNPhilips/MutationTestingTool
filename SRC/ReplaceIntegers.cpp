#include "ReplaceIntegers.h"

ReplaceIntegers::ReplaceIntegers()
{
    
}

ReplaceIntegers::~ReplaceIntegers()
{

}

bool ReplaceIntegers::Mutate(string& s)
{
    cout << "\n entered Mutate in Replace integers :\n";
    const char* c = s.c_str();
    bool result = false;

    cout << "\n replace number : " << s << "\n";
    string::const_iterator it = s.begin();
    for (int i = 0; it != s.end(); i++, it++)
    {
        if (isdigit(*it))
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
