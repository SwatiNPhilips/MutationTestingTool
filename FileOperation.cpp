#include<iostream>
#include<fstream>
#include "FileOperation.h"
#include"MutateOperation.h"
#include"ReplaceIntegers.h"
#include"Report.h"

using namespace std;

class MutateOperation;

FileOperation::FileOperation(string name, string path)
{
	file_name = name;
	file_path = path;
	absolute_path = path + "/" + name;
	lines_count = line_number = 0;
	read_offset = write_offset = 0;

	cout << "\n constructor :\n" << "\nFile name :" << file_name << "\nFile path: " << file_path;
}

FileOperation::~FileOperation()
{
	file_name.clear();
	file_path.clear();
	absolute_path.clear();
	lines_count = line_number = 0;
	read_offset = write_offset = 0;
}

void FileOperation::init()
{
	database_folder = "/home/philips/Repo/Mutate_Factory/MutationTesting";
	CreateDB_Folder();
	copyOriginalFile();
}

bool FileOperation::File_Read(MutateOperation* MutateOp, std::map<std::string, REPORT>* mpReport, string mapIndex)
{
//	cout << "\n\nfile read\n";

	ifstream fin;
	string line;
	bool result = false;

	fin.open(absolute_path.c_str());
	
	if (fin.is_open())
	{
//		cout << "\n \n -----------\n";
		fin.seekg(read_offset);
		if (getline(fin, line))
		{
//			cout << "read line : " << line << "\n";
			cout << fin.tellg();
			read_offset = fin.tellg();
			line_number++;
			result = File_write(line, MutateOp,mpReport,mapIndex);
//			cout << "\n \n -----------\n";
		}

	}
	return result;
}

bool FileOperation::File_write(string line, MutateOperation* MutateOp, std::map<std::string, REPORT>* mpReport, string mapIndex)
{
//	cout << "\n\n file wite \n";
	bool result = false;
	ofstream fout;
	fout.open(absolute_path.c_str(), fstream::in | fstream::out);

	if (fout.is_open())
	{
//		cout << "\nwrite file open  \n";
		if (MutateOp->Mutate(line)) {
			fout.seekp(write_offset);
			fout << line;

			(*mpReport)[mapIndex].lines.push_back((to_string(line_number) + " : " + line));
			(*mpReport)[mapIndex].mutants_count++;

		cout << "\n \n -----------\n";
		cout << " write line : " << line << "\n";
		cout << "\n \n -----------\n";
   
			result = true;
		}
		write_offset = read_offset;

		fout.close();
	}

	return result;
}

int FileOperation::getLinesCount()
{
	cout << "\n\nfile count\n";

	if (lines_count > 0)
		return lines_count;

	ifstream fin;
	string line;
	fin.open(absolute_path.c_str());

	lines_count = 0;

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			lines_count++;
		}

	}
	return lines_count;
}

void FileOperation::CreateDB_Folder()
{
	string cmd = "mkdir " + database_folder;
	system(cmd.c_str());
	cmd = "mkdir " + database_folder + "/" + file_name + "_db";
	system(cmd.c_str());

	database_folder = database_folder + "/" + file_name + "_db";
	cout << "\n Called CreateDB_Folder " << database_folder;
}

void FileOperation::copyOriginalFile()
{
	string folder = database_folder + "/original";
	string cmd = "mkdir " + folder;
	system(cmd.c_str());
	cmd = "cp " + file_path + "/" + file_name +" " + folder;
	system(cmd.c_str());
	original_file_folder = folder;
	cout << "\n Called copyOriginalFile " << original_file_folder;
}


void FileOperation::ReplaceOriginalFile()
{
	cout << "\n Called ReplaceOriginalFile ";
	
	string cmd = "cp " + original_file_folder + "/" + file_name + " " + file_path;
	system(cmd.c_str());
}

vector<string> FileOperation::Read_Config()
{
	ifstream fin;
	string line;
	vector<string> result;
	result.clear();

	fin.open(absolute_path.c_str());

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if ((line.find(";") != string::npos) && (line.find("#") == string::npos))
			{
				result.push_back(line);
			}
		}
	}
	return result;
}

string FileOperation::GetFileName()
{
	return file_name;
}
