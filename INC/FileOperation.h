#pragma once
#include "MutateOperation.h"
#include "Report.h"

class FileOperation
{
    fs::path file_name;
    fs::path file_path;
    string absolute_path;
    fs::path database_folder;

    streamoff read_offset;
    streamoff write_offset;

    int lines_count;
    int line_number;
    static string m_cmdReplace;

    bool file_write(string, MutateOperation*, map<string, REPORT>*, const string);

public : 
    FileOperation(fs::path, fs::path);
    ~FileOperation();
    FileOperation(const FileOperation& obj) = delete;
    FileOperation& operator = (const FileOperation& obj) = delete;

    bool file_Read(MutateOperation*, map<string, REPORT>*, const string);

    int getLinesCount();
    void replaceOriginalFile() const;
    bool createDB_Folder();
    void copyOriginalFile();
    void removeDB_Folder() const;
    void performActionOnInterrupt() const;

    string getFileName() const;
};

