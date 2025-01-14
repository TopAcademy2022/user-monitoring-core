#include "windows-factory.h"

std::unique_ptr<AbstractOS> WindowsFactory::CreateInstance()
{
    return std::unique_ptr<WorkWindows>();
}