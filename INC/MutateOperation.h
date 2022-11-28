#pragma once
#include <string>
#include<iostream>
#include"MiscEnums.h"

using namespace std;

class MutateOperation
{
public:
	MutateOperation();
	virtual ~MutateOperation();
	virtual bool Mutate(std::string& s) =0;

};


