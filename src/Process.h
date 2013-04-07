#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <signal.h>

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
    Process(Process const & p) = delete;
    Process & operator=(Process const & p) = delete;
    ~Process();

    void wait();
    std::string getLogPath() const;
    int getExitStatus();
    int getPid() const;
    /* FIXME Implement a SIGCHLD monitor to truely track the state of child
     * processes, rather than this hacky internal class state. */
    State getState() const;
    void stop();
    int kill(int signal=SIGTERM);
};

#endif
