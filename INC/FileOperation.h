#pragma once
#include "MutateOperation.h"
#include "Report.h"

class FileOperation
{
    fs::path m_fileName;
    fs::path m_filePath;
    string m_absolutePath;
    fs::path m_databaseFolder;

    streamoff m_readOffset;
    streamoff m_writeOffset;

    int m_linesCount;
    int m_lineNumber;
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

