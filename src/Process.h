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
    std::string logPath;
    int logFD;
    void initLog();

    static void runChild(std::string const & command, int logfd = -1);

    public:

    Process(std::string const & cmd);
    pid_t run();
    pid_t wait();
    std::string getLogPath();
    int getStatus();
};

#endif
