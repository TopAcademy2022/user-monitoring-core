#include "main.h" 
#include <signal.h> 
#include <dirent.h> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio>

class TaskManager
{
public:
    bool TaskManager::TerminateProcessbyProgramName(const char* programName);
};

EXPORT void TerminateProcessByProgName(char* progName);