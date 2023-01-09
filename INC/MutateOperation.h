#pragma once
#include"MiscEnums.h"

class MutateOperation
{
public:
	MutateOperation();
	virtual ~MutateOperation();
	virtual bool Mutate(string& s) =0;

};


