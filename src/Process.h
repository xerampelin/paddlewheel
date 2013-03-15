#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <string>

#include <boost/signal.hpp>

class Process
{

    int pid_;
    int status_;
    std::string const command_;

    public:
    boost::signal <void (int)> sigFinish;

    Process(std::string const & command):
        pid_(-1),
        status_(-1),
        command_(command) {}

    pid_t run();
    pid_t wait();
};

#endif
