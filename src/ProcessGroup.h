#ifndef _PROCESS_GROUP_H_
#define _PROCESS_GROUP_H_

#include <iostream>
#include <list>
#include <memory>

#include "Process.h"

class ProcessGroup
{
    typedef std::vector<std::shared_ptr<Process> > ProcVector;
    int runningProcs;
    int maxProcs;
    ProcVector processes;
    std::list<std::string> commands;

    void run();
    /* FIXME add test for copying */
    Process & operator=(Process & p) {}

    public:
        ProcessGroup(int maxProcesses);
        void add(std::string command);
        std::shared_ptr<Process> operator[](int index)
        {
            return processes[index];
        }
        void waitAll();
};

#endif // #if _PROCESS_GROUP_H_
