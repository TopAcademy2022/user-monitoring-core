#if defined(_MSC_VER)
    // Microsoft
    #define EXPORT extern "C" __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    // GCC
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
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