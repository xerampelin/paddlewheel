#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <string>

#include <boost/signal.hpp>
#include <boost/algorithm/string.hpp>

class Process
{
    int pid;
    int status;
    std::string const command;

    public:

    Process(std::string const & cmd):
        pid(-1),
        status(-1),
        command(cmd)
    {
    }

    pid_t run();
    pid_t wait();
};

#endif
