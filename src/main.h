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


class TaskManager
{
private:
    bool TerminateProcess(char* programName);
};

EXPORT void TerminateProcessByProgName(char* progName);