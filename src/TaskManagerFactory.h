#ifndef TASKMANAGERFACTORY_H
#define TASKMANAGERFACTORY_H

#include "TaskManager.h"

class TaskManagerFactory {
public:
    static TaskManager* CreateTaskManager();
};

#endif // TASKMANAGERFACTORY_H