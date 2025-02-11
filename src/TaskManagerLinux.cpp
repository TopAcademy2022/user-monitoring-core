TaskManagerLinux.h

void TerminateProcessByProgName(const char* progName) 
{ 
    TaskManager* taskManager = new TaskManager(); 
    taskManager->TerminateProcessbyProgramName(progName); 
} 
 
bool TaskManager::TerminateProcessbyProgramName(const char* programName) 
{ 
    DIR* dir = opendir("/proc"); 
    if (!dir) return false; 
 
    struct dirent* entry; 
    while ((entry = readdir(dir)) != nullptr) 
    { 
        if (entry->d_type == DT_DIR) 
        { 
            pid_t pid = atoi(entry->d_name); 
            if (pid > 0) 
            { 
                char cmdlinePath[256]; 
                snprintf(cmdlinePath, sizeof(cmdlinePath), "/proc/%d/cmdline", pid); 
                 
                FILE* cmdlineFile = fopen(cmdlinePath, "r"); 
                if (cmdlineFile) 
                { 
                    char cmdline[256]; 
                    fgets(cmdline, sizeof(cmdline), cmdlineFile); 
                    fclose(cmdlineFile); 

                    if (strstr(cmdline, programName) != nullptr) 
                    { 
                        kill(pid, SIGTERM); 
                        closedir(dir); 
                        return true; 
                    } 
                } 
            } 
        } 
    } 
    closedir(dir); 
    return false; 
}