#pragma once
#include "MiscEnums.h"

class Execute
{
    fs::path  m_buildPath;
    string  m_buildCommand;
    fs::path  m_runPath;
    string  m_runCommand;

    string readConsole(const string) const;
    void resetDetails();
public:
    Execute();
    ~Execute();
    Execute(const Execute& obj) = delete;
    Execute& operator = (const Execute& obj) = delete;

    void setExecuteDetails(const COMMANDS);
    bool validateExecutePath();
    void buildCode();
    MAP_CMD_OP runCode();

};

