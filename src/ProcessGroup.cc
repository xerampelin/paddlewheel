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
}
