#include "ReplaceDivisionWithMultiplication.h"
ReplaceDivisionWithMultiplication* ReplaceDivisionWithMultiplication::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplaceDivisionWithMultiplication::ReplaceDivisionWithMultiplication()
{

}

ReplaceDivisionWithMultiplication::~ReplaceDivisionWithMultiplication()
{

}

bool ReplaceDivisionWithMultiplication::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplaceDivisionWithMultiplication : " << line << "\n";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if(line[i] == DIVISION)
        {
            line[i] = MULTIPLICATION;
            result = true;
            
        }
    }

   return result;
}
