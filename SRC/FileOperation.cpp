#include<fstream>
#include "FileOperation.h"
#include"MutateOperation.h"
#include"ReplaceIntegers.h"
#include"Report.h"

static constexpr char SEPERATOR[] = "/";
static constexpr char BACKUPDB[] = "./BackupDB/";
static constexpr char DB_EXT[] = "_db";
static constexpr char CMDMKDIR[] = "mkdir";
static constexpr char SPACE[] = " ";
static constexpr char CMDCP[] = "cp";
static constexpr char ORIGINAL[] = "original";
static constexpr char SEMICOLON[] = ";";

FileOperation::FileOperation(string name, string path)
{
	file_name = name;
	file_path = path;
	absolute_path = path + SEPERATOR + name;
	lines_count = line_number = 0;
	read_offset = write_offset = 0;
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
	database_folder = BACKUPDB;
	CreateDB_Folder();
	copyOriginalFile();
}

bool FileOperation::File_Read(MutateOperation* MutateOp, map<string, REPORT>* mpReport, const string mapIndex)
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

bool FileOperation::File_write(string line, MutateOperation* MutateOp, map<string, REPORT>* mpReport, const string mapIndex)
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
	string cmd = CMDMKDIR + string(SPACE) + database_folder + SEMICOLON + CMDMKDIR + string(SPACE) + database_folder + file_name + DB_EXT;
#ifdef _WIN32
	FILE* pipe = _popen(cmd.c_str(), "r");
#else
	FILE* pipe = popen(cmd.c_str(), "r");
#endif
	if (!pipe) {
		cout << "popen failed! for CreateDB_Folder" << endl;
	}

#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
	database_folder = database_folder + file_name + DB_EXT;
	cout << "\n Called CreateDB_Folder " << database_folder;
}

void FileOperation::copyOriginalFile()
{
	string folder = database_folder + SEPERATOR + ORIGINAL;
	string cmd = CMDMKDIR + string(SPACE) + folder + SEMICOLON + CMDCP + string(SPACE) + file_path + SEPERATOR + file_name + SPACE + folder;

#ifdef _WIN32
	FILE* pipe = _popen(cmd.c_str(), "r");
#else
	FILE* pipe = popen(cmd.c_str(), "r");
#endif
	if (!pipe) {
		cout << "popen failed! for copyOriginalFile" << endl;
	}
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
	original_file_folder = folder;
	//cout << "\n Called copyOriginalFile " << original_file_folder;
}


void FileOperation::ReplaceOriginalFile() const
{
	//cout << "\n Called ReplaceOriginalFile ";
	
	string cmd = CMDCP + string(SPACE) + original_file_folder + SEPERATOR + file_name + SPACE + file_path;
#ifdef _WIN32
	FILE* pipe = _popen(cmd.c_str(), "r");
#else
	FILE* pipe = popen(cmd.c_str(), "r");
#endif
	if (!pipe) {
		cout << "popen failed! for ReplaceOriginalFile" << endl;
	}
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
}

string FileOperation::GetFileName() const
{
	return file_name;
}