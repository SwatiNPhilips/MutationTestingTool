#pragma once
class ExecuteClass
{
	std::string  hl7_path;
public:
	ExecuteClass();
	~ExecuteClass();
	void buildCode();
	std::string runCode();

};

