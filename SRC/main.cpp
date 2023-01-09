#include"MutateFactory.h"
#include"ConfigurationFile.h"

int main(int argc, char* argv[])
{
	cout << "\n Main function : ";
	ConfigurationFile* cf = new ConfigurationFile();
	if (cf != nullptr)
	{
		MutateFactory* fp = new MutateFactory();
		fp->setConfiguration(cf->PopulateConfigStruct());
		delete cf;
		cf = nullptr;
   
		if (fp != nullptr)
		{
			fp->initMutate();
			fp->printReport();

			delete fp;
			fp = nullptr;
		}
	}
}