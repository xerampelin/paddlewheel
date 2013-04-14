#ifndef _PROCESS_GROUP_H_
#define _PROCESS_GROUP_H_

#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "Process.h"

class ProcessPool
{
    typedef std::vector<std::shared_ptr<Process> > ProcVector;
    typedef ProcVector::iterator iterator;

    int runningProcs;
    int maxProcs;
    ProcVector processes;
    std::list<std::string> commands;

    void run();

    ProcessPool & operator=(ProcessPool) = delete;

    public:
        ProcessPool(int maxProcesses = 2);
        void add(std::string command);
        std::shared_ptr<Process> operator[](int index)
        {
            return processes[index];
        }
        void waitAll();
        /* TODO may consider making this class extend a vector instead of
         * reimplementing a bunch of the same methods.. */
        iterator begin()
        {
            return processes.begin();
        }
        
        iterator end()
        {
            return processes.end();
        }

};

#endif // #if _PROCESS_GROUP_H_
