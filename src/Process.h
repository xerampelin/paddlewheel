#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <string>

#include <boost/signal.hpp>
#include <boost/algorithm/string.hpp>

class Process
{
public:
    enum State
    {
        COMMENCING,
        STARTED,
        FINISHED
    };

private:
    int pid;
    int exitStatus;
    std::string const command;
    std::string logPath;
    int logFD;
    Process::State state;

    void initLog();
    void run();

    static void runChild(std::string const & command, int logfd = -1);

public:

    Process(std::string const & cmd);
    void wait();
    std::string getLogPath() const;
    int getExitStatus();
    int getPid() const;
    State getState() const;
};

#endif
