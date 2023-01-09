#pragma once
#include"MutateOperation.h"
#include"ReplaceIntegers.h"
#include"Report.h"

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

	bool File_write(string, MutateOperation*, map<string, REPORT>*, const string);

public : 
	FileOperation(string, string);
	~FileOperation();
	void init();

	bool File_Read(MutateOperation*, map<string, REPORT>*, const string);

	int getLinesCount();
	void copyOriginalFile();
	void ReplaceOriginalFile() const;
	void CreateDB_Folder();

	string GetFileName() const;
};

