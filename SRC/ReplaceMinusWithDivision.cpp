#include "ReplaceMinusWithDivision.h"
ReplaceMinusWithDivision* ReplaceMinusWithDivision::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char EQUALTO = '=';
static constexpr char GREATER = '>';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplaceMinusWithDivision::ReplaceMinusWithDivision()
{

}

ReplaceMinusWithDivision::~ReplaceMinusWithDivision()
{

}

bool ReplaceMinusWithDivision::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplaceMinusWithDivision : " << line << "\n";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if(line[i] == MINUS && i < line.length() - 1)
        {
            if(line[i+1] == MINUS
            || line[i+1] == SEMICOLON
            || line[i+1] == EQUALTO
            || line[i+1] == GREATER)
            {
                i++;
            }
            else if(line[i+1] == WHITESPACE)
            {
                unsigned int j = i+1;
                while(j != line.length() && line[j] == WHITESPACE) j++;
                if(j == line.length()) break;
                if(line[j] != SEMICOLON)
                {
                    line[i] = DIVISION;
                    result = true;
                }
                i = j;
            }
            else
            {
                line[i] = DIVISION;
                result = true;
            }
        }
    }

   return result;
}
