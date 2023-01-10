#include "ReplaceMultiplicationWithDivision.h"
ReplaceMultiplicationWithDivision* ReplaceMultiplicationWithDivision::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char GREATER = '>';
static constexpr char DOT = '.';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplaceMultiplicationWithDivision::ReplaceMultiplicationWithDivision()
{

}

ReplaceMultiplicationWithDivision::~ReplaceMultiplicationWithDivision()
{

}

bool ReplaceMultiplicationWithDivision::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplaceMultiplicationWithDivision : " << line << "\n";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if(line[i] == MULTIPLICATION && i < line.length() - 1)
        {
            if(line[i+1] == MULTIPLICATION 
            || (i > 0 && line[i-1] == DOT)
            || (i > 1 && line[i-1] == GREATER && line[i-2] == MINUS))
            {
                i++;
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
