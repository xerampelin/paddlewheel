#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <string>

#include <boost/signal.hpp>
#include <boost/algorithm/string.hpp>

class Process
{
    typedef std::vector<std::string> VecStr;

    int pid;
    int status;
    VecStr const command;

    static std::string generateLogName(VecStr const & cmd);
    static VecStr toVecStr(std::string const & s)
    {
        VecStr vs;
        boost::split(vs, s, ::isspace);
        return vs;
    }

    public:
    std::string const logName;

    Process(std::string const & cmd):
        pid(-1),
        status(-1),
        command(toVecStr(cmd)),
        logName(generateLogName(command)) {}

    pid_t run();

    pid_t wait();

};

#endif
