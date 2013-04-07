#include "ProcessPool.h"
#include "Process.h"

ProcessPool::ProcessPool(int maxProcesses):
    runningProcs(0),
    maxProcs(maxProcesses)
{
}

void ProcessPool::add(std::string command)
{
    commands.push_back(command);

    if (runningProcs < maxProcs) {
        run();
    }
}

void ProcessPool::run()
{
    std::shared_ptr<Process> p(new Process(commands.front()));
    processes.push_back(p);
    runningProcs++;
    commands.pop_front();
}

void ProcessPool::waitAll()
{
    for (auto i = processes.begin(); i != processes.end(); ++i) {
        if ((*i)->getState() == Process::STARTED) {
            (*i)->wait();
        }
    }
}
