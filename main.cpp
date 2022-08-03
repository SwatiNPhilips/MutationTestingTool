#include <iostream>
#include <fstream>
#include<string>
#include "FileOperation.h"
#include"MutateFactory.h"
#include"ConfigurationFile.h"

using namespace std;
int main(int argc, char* argv[])
{
	cout << "\n Main function : ";
	ConfigurationFile* cf = new ConfigurationFile();
	if (cf != nullptr)
	{
		MutateFactory* fp = new MutateFactory(cf->PopulateConfigStruct());
   
		delete cf;
		cf = nullptr;
   
		if (fp != nullptr)
		{
			fp->initMutate();
			fp->PrintReport();

			delete fp;
			fp = nullptr;
		}
	}
}