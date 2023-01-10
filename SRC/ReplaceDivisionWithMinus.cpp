#include "ReplaceDivisionWithMinus.h"
ReplaceDivisionWithMinus* ReplaceDivisionWithMinus::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplaceDivisionWithMinus::ReplaceDivisionWithMinus()
{

}

ReplaceDivisionWithMinus::~ReplaceDivisionWithMinus()
{

}

bool ReplaceDivisionWithMinus::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplaceDivisionWithMinus : " << line << "\n";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if(line[i] == DIVISION)
        {
            line[i] = MINUS;
            result = true;
            
        }
    }

   return result;
}
