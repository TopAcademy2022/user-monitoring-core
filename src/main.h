#if defined(_MSC_VER)
    // Microsoft
    #define EXPORT extern "C" __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
    #include "work-windows.h"
#elif defined(__GNUC__)
    // GCC
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
    #include "work-linux.h"
#else
    #define EXPORT
    #define IMPORT
    #pragma warning Not found import/export semantics.
#endif


#if MY_LIB_COMPILING
#   define PUBLIC_FUNCTION EXPORT
#else
#   define PUBLIC_FUNCTION IMPORT
#endif


#include "iwork-os.h"
#include "abstract-os.h"
#include "os-factory.h"
#include "windows-factory.h"


class TaskManager
{
private:
    bool TerminateProcess(char* programName);
};

EXPORT void TerminateProcessByProgName(char* progName);