#include "main.h"

void TerminateProcessByProgName(char* progName)
{
    OSFactory* factory = new WindowsFactory();
    std::unique_ptr<IWorkOS> os = factory->CreateInstance();
    IWorkOS* pointer = os.get();
    pointer->TerminateProc();
}

bool TaskManager::TerminateProcess(char* programName)
{
    return false;
}
