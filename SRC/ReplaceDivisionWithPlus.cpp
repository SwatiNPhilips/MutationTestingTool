#include "ReplaceDivisionWithPlus.h"
ReplaceDivisionWithPlus* ReplaceDivisionWithPlus::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplaceDivisionWithPlus::ReplaceDivisionWithPlus()
{

}

ReplaceDivisionWithPlus::~ReplaceDivisionWithPlus()
{

}

bool ReplaceDivisionWithPlus::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplaceDivisionWithPlus : " << line << "\n";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if(line[i] == DIVISION)
        {
            line[i] = PLUS;
            result = true;
            
        }
    }

   return result;
}
