#include <windows.h>    
#include <tlhelp32.h>  
#include <cstring>
#include <cstdio>


class TaskManager
{
public:
    bool TerminateProcessbyProgramName(char* programName);
};

EXPORT void TerminateProcessByProgName(char* progName);