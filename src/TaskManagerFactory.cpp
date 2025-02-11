#include "TaskManagerFactory.h"
#include <iostream>

#ifdef _WIN32
#include "TaskManagerWindows.h"
#else
#include "TaskManagerLinux.h"
#endif

TaskManager* TaskManagerFactory::CreateTaskManager() {
#ifdef _WIN32
    return new TaskManagerWindows();
#else
    return new TaskManagerLinux();
#endif
}