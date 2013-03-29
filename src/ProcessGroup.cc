#include "ProcessGroup.h"
#include "Process.h"

ProcessGroup::ProcessGroup(int maxProcesses):
    runningProcs(0),
    maxProcs(maxProcesses)
{
}

void ProcessGroup::add(std::string command)
{
    commands.push_back(command);

    if (runningProcs < maxProcs) {
        run();
    }
}

void ProcessGroup::run()
{
    std::shared_ptr<Process> p(new Process(commands.front()));
    processes.push_back(p);
    runningProcs++;
    commands.pop_front();
}

void ProcessGroup::waitAll()
{
    for (auto i = processes.begin(); i != processes.end(); ++i) {
        if ((*i)->getState() == Process::STARTED) {
            (*i)->wait();
        }
    }
}
