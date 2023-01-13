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
    file_name = name;
    file_path = path;
    database_folder.clear();
    absolute_path = (path / name).string();
    lines_count = line_number = 0;
    read_offset = write_offset = 0;
}

FileOperation::~FileOperation()
{
    file_name.clear();
    file_path.clear();
    database_folder.clear();
    absolute_path.clear();
    lines_count = line_number = 0;
    read_offset = write_offset = 0;
}

bool FileOperation::file_Read(MutateOperation* pMutateOp, map<string, REPORT>* pReport, const string mapIndex)
{
    ifstream fin;
    string line;
    bool result = false;

    try
    {
        fin.open(absolute_path.c_str());

        if (fin.is_open())
        {
            fin.seekg(read_offset);
            if (getline(fin, line))
            {
                read_offset = fin.tellg();
                line_number++;
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
        fout.open(absolute_path.c_str(), fstream::in | fstream::out);

        if (fout.is_open())
        {
            if (pMutateOp->Mutate(line))
            {
                fout.seekp(write_offset);
                fout << line;

                (*pReport)[mapIndex].lines.emplace_back((to_string(line_number) + " : " + line));
                (*pReport)[mapIndex].mutants_count++;
                result = true;
            }
            write_offset = read_offset;
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
    if (lines_count > 0)
    {
        return lines_count;
    }

    ifstream fin;
    string line;
    try
    {
        fin.open(absolute_path.c_str());

        lines_count = 0;

        if (fin.is_open())
        {
            while (getline(fin, line))
            {
                lines_count++;
            }

        }
    }
    catch(exception const& ex)
    {
        cout<<endl<<ex.what()<<endl;;
    }
    return lines_count;
}

bool FileOperation::createDB_Folder()
{
    bool status = true;
    fs::path backup_path(BACKUPDB);
    database_folder = fs::current_path() / backup_path;
    if(!fs::exists(database_folder))
    {
        if( !boost::filesystem::create_directory(database_folder))
        {
            cout<<" execution of createDB_Folder failed"<<endl;
            status = false;
        }
    }
    FileOperation::m_cmdReplace = CMDCP + string(SPACE) + (database_folder / file_name).string() + SPACE 
                         + file_path.string() + SEMICOLON + CMDRM + SPACE + CMDRF + SPACE + database_folder.string();
    return status;
}

void FileOperation::removeDB_Folder() const
{
    if (fs::exists(database_folder)) 
    {
        fs::remove_all(database_folder);
    }
}

void FileOperation::copyOriginalFile()
{
    fs::path fileName = database_folder / file_name;
#ifdef _WIN32
    fs::copy_file(absolute_path, fileName , fs::copy_options::overwrite_existing);
#else
    fs::copy_file(absolute_path, fileName , fs::copy_option::overwrite_if_exists);
#endif
}

void FileOperation::replaceOriginalFile() const
{
    fs::path backup_path = database_folder / file_name;
    fs::path abs_path = file_path / file_name;

#ifdef _WIN32
    fs::copy_file(backup_path, abs_path, fs::copy_options::overwrite_existing);
#else
    fs::copy_file(backup_path, abs_path, fs::copy_option::overwrite_if_exists);
#endif
}

string FileOperation::getFileName() const
{
    return file_name.string();
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