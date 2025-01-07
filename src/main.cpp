#include "main.h"

void TerminateProcessByProgName(char* progName)
{
    TaskManager* taskManager = new TaskManager();
    taskManager->TerminateProcessbyProgramName(progName);
}

bool TaskManager::TerminateProcessbyProgramName(char* programName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) return false;

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);


    if (Process32First(hSnapshot, &processEntry))
    {
        do {
            char fullProgramName[256];
            snprintf(fullProgramName, sizeof(fullProgramName), "%s.exe", programName);

            if (_stricmp(processEntry.szExeFile, fullProgramName) == 0)
            {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processEntry.th32ProcessID);
                if (hProcess != NULL) 
                {
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                    CloseHandle(hSnapshot);
                    return true;
                }
            }
        } while (Process32Next(hSnapshot, &processEntry));
    }
    CloseHandle(hSnapshot);
    return false;
}