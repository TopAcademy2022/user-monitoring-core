#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>

class TaskManager {
public:
    virtual ~TaskManager() = default;

    // Метод для завершения процесса по имени
    virtual bool TerminateProcessbyProgramName(const char* programName) = 0;
};

#endif // TASKMANAGER_H