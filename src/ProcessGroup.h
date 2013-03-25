#ifndef _PROCESS_GROUP_H_
#define _PROCESS_GROUP_H_

#include <iostream>
#include <list>

#include "Process.h"

class ProcessGroup
{
    int runningProcs;
    int maxProcs;
    std::list<Process> processes;
    std::list<std::string> commands;

    public:
        ProcessGroup(int maxProcesses);
        void add(std::string command);
};

#endif // #if _PROCESS_GROUP_H_
