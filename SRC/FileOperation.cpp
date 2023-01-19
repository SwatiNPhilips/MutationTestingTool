#include <fstream>
#include "FileOperation.h"

static constexpr char BACKUPDB[] = "BackupDB";
static constexpr char CMDMKDIR[] = "mkdir";
static constexpr char SPACE[] = " ";
static constexpr char CMDCP[] = "cp";
static constexpr char SEMICOLON[] = ";";
static constexpr char CMDRM[] = "rm";
static constexpr char CMDRF[] = "-rf";

string FileOperation::m_cmdReplace = "";

FileOperation::FileOperation(fs::path name, fs::path path)
{
    m_fileName = name;
    m_filePath = path;
    m_databaseFolder.clear();
    m_absolutePath = (m_filePath / m_fileName).string();
    m_linesCount = m_lineNumber = 0;
    m_readOffset = m_writeOffset = 0;
}

FileOperation::~FileOperation()
{
    m_fileName.clear();
    m_filePath.clear();
    m_databaseFolder.clear();
    m_absolutePath.clear();
    m_linesCount = m_lineNumber = 0;
    m_readOffset = m_writeOffset = 0;
}

bool FileOperation::file_Read(MutateOperation* pMutateOp, map<string, REPORT>* pReport, const string mapIndex)
{
    ifstream fin;
    string line;
    bool result = false;

    try
    {
        fin.open(m_absolutePath.c_str());

        if (fin.is_open())
        {
            fin.seekg(m_readOffset);
            if (getline(fin, line))
            {
                m_readOffset = fin.tellg();
                m_lineNumber++;
                result = file_write(line, pMutateOp,pReport,mapIndex);
            }
        }
    }
    catch(exception const& ex)
    {
        cout<<endl<<ex.what()<<endl;;
    }
    return result;
}

bool FileOperation::file_write(string line, MutateOperation* pMutateOp, map<string, REPORT>* pReport, const string mapIndex)
{
    bool result = false;
    ofstream fout;
    try
    {
        fout.open(m_absolutePath.c_str(), fstream::in | fstream::out);

        if (fout.is_open())
        {
            if (pMutateOp->Mutate(line))
            {
                fout.seekp(m_writeOffset);
                fout << line;

                (*pReport)[mapIndex].lines.emplace_back((to_string(m_lineNumber) + " : " + line));
                (*pReport)[mapIndex].mutants_count++;
                result = true;
            }
            m_writeOffset = m_readOffset;
            fout.close();
        }
    }
    catch(exception const& ex)
    {
        cout<<endl<<ex.what()<<endl;;
    }
    return result;
}

int FileOperation::getLinesCount()
{
    if (m_linesCount > 0)
    {
        return m_linesCount;
    }

    ifstream fin;
    string line;
    try
    {
        fin.open(m_absolutePath.c_str());

        m_linesCount = 0;

        if (fin.is_open())
        {
            while (getline(fin, line))
            {
                m_linesCount++;
            }

        }
    }
    catch(exception const& ex)
    {
        cout<<endl<<ex.what()<<endl;;
    }
    return m_linesCount;
}

bool FileOperation::createDB_Folder()
{
    bool status = true;
    fs::path backup_path(BACKUPDB);
    m_databaseFolder = fs::current_path() / backup_path;
    if(!fs::exists(m_databaseFolder))
    {
        if( !boost::filesystem::create_directory(m_databaseFolder))
        {
            cout<<" execution of createDB_Folder failed"<<endl;
            status = false;
        }
    }
    FileOperation::m_cmdReplace = CMDCP + string(SPACE) + (m_databaseFolder / m_fileName).string() + SPACE 
                         + m_filePath.string() + SEMICOLON + CMDRM + SPACE + CMDRF + SPACE + m_databaseFolder.string();
    return status;
}

void FileOperation::removeDB_Folder() const
{
    if (fs::exists(m_databaseFolder)) 
    {
        fs::remove_all(m_databaseFolder);
    }
}

void FileOperation::copyOriginalFile()
{
    fs::path fileName = m_databaseFolder / m_fileName;
#ifdef _WIN32
    fs::copy_file(m_absolutePath, fileName , fs::copy_options::overwrite_existing);
#else
    fs::copy_file(m_absolutePath, fileName , fs::copy_option::overwrite_if_exists);
#endif
}

void FileOperation::replaceOriginalFile() const
{
    fs::path backup_path = m_databaseFolder / m_fileName;
    fs::path abs_path = m_filePath / m_fileName;

#ifdef _WIN32
    fs::copy_file(backup_path, abs_path, fs::copy_options::overwrite_existing);
#else
    fs::copy_file(backup_path, abs_path, fs::copy_option::overwrite_if_exists);
#endif
}

string FileOperation::getFileName() const
{
    return m_fileName.string();
}

void FileOperation::performActionOnInterrupt() const
{
#ifdef _WIN32
    FILE* pipe = _popen(FileOperation::m_cmdReplace.c_str(), "r");
#else
    FILE* pipe = popen(FileOperation::m_cmdReplace.c_str(), "r");
#endif
    if (!pipe)
    {
        cout << "popen failed! for ReplaceOriginalFile" << endl;
    }
#ifdef _WIN32
    _pclose(pipe);
#else
    pclose(pipe);
#endif
}