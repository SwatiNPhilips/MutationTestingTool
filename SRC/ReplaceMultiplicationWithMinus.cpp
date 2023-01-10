#include "ReplaceMultiplicationWithMinus.h"
ReplaceMultiplicationWithMinus* ReplaceMultiplicationWithMinus::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char GREATER = '>';
static constexpr char DOT = '.';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplaceMultiplicationWithMinus::ReplaceMultiplicationWithMinus()
{

}

ReplaceMultiplicationWithMinus::~ReplaceMultiplicationWithMinus()
{

}

bool ReplaceMultiplicationWithMinus::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplaceMultiplicationWithMinus : " << line << "\n";
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
                line[i] = MINUS;
                result = true;
            }
        }
    }

   return result;
}
