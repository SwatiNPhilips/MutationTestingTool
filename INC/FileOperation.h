#pragma once
#include<string>
#include"MutateOperation.h"
#include"ReplaceIntegers.h"
#include<vector>
#include<map>
#include"Report.h"

class MutateOperation;

using namespace std;
class FileOperation
{
	string file_name;
	string file_path;
	string absolute_path;


	string database_folder;
	string original_file_folder;

	streamoff read_offset;
	streamoff write_offset;

	int lines_count;
	int line_number;

	bool File_write(string, MutateOperation*, std::map<std::string, REPORT>* mpReport, string mapIndex);

public : 
	FileOperation(string, string);
	~FileOperation();
	void init();

	bool File_Read(MutateOperation* MutateOp, std::map<std::string, REPORT>* mpReport, string mapIndex);

	vector<string> Read_Config();

	int getLinesCount();
	void copyOriginalFile();
	void ReplaceOriginalFile();
	void CreateDB_Folder();

	string GetFileName();
};

