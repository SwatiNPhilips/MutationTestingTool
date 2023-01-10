#include "ReplacePlusWithMinus.h"
ReplacePlusWithMinus* ReplacePlusWithMinus::m_Instance = nullptr;

static constexpr char PLUS = '+';
static constexpr char MINUS = '-';
static constexpr char MULTIPLICATION = '*';
static constexpr char DIVISION = '/';
static constexpr char EQUALTO = '=';
static constexpr char WHITESPACE = ' ';
static constexpr char SEMICOLON = ';';

ReplacePlusWithMinus::ReplacePlusWithMinus()
{

}

ReplacePlusWithMinus::~ReplacePlusWithMinus()
{

}

bool ReplacePlusWithMinus::Mutate(std::string& line)
{
	bool result = false;
	cout << "\n ReplacePlusWithMinus : " << line << "\n";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if(line[i] == PLUS && i < line.length() - 1)
        {
            if(line[i+1] == PLUS
            || line[i+1] == SEMICOLON
            || line[i+1] == EQUALTO)
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
                    line[i] = MINUS;
                    result = true;
                }
                i = j;
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
