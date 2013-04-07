#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sysexits.h>
#include <sstream>

#include <glib.h>

#include "Process.h"

using std::string;
using std::vector;

Process::Process(std::string const & cmd):
    pid(-1),
    exitStatus(-1),
    command(cmd),
    logFD(-1),
    state(COMMENCING)
{
    initLog();
    run();
}

Process::~Process()
{
    try {
        stop();
    } catch (...) {
    }
}

/* Process is a class that runs a single process.  We'll start by defining
 * the main thing people want to do with this class--run a process.
 *
 * Most of the work will be handled by helper functions (explained shortly).
 * 
 * In the run method we will just fork and return, storing the child's pid along
 * the way.  The child will call exec and never return, but just in case we'll
 * also exit with an error after exec'ing.
 */
void Process::run()
{
    state = STARTED;
    pid = fork();
    if (pid < 0) {
        string msg("Fork failed: ");
        msg += strerror(errno);
        throw std::runtime_error(msg);
    }

    if (pid == 0) {
        runChild(command, logFD);
    }
    g_message("Started process %d ==> %s", pid, command.c_str());
}

void Process::initLog()
{
    vector<string> argv;
    /* TODO this is probably overkill for just finding the string up to the
     * first space. */
    boost::split(argv, command, ::isspace);

    if (argv.size() < 0) {
        throw std::runtime_error("Could not find any commands in '"
                                 + command + "'");
    }

    logPath = argv[0] + ".log.XXXXXX";

    /* FIXME Yay hacks!  We're modifying the buffer a string class holds without
     * telling it.  But we're not changing the length of the string, so it'll be
     * okay right?! right?!*/
    int rc = mkstemp((char *)logPath.c_str());
    if (rc == -1) {
        string msg("Couldn't create log file: ");
        msg += strerror(errno);
        throw std::runtime_error(msg);
    }
    
    int permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    logFD = open(logPath.c_str(),
                  O_WRONLY | O_CREAT | O_TRUNC,
                  permissions);
    if (logFD < 0) {
        string msg = "Error opening " + logPath;
        throw std::runtime_error(msg);
    }
}

void Process::runChild(std::string const & command, int logfd)
{
    char const * SHELL = "/bin/sh";

    /* FIXME don't write both streams to the same file.. */
    if (logfd >= 0) {
        dup2(logfd, STDOUT_FILENO);
        dup2(logfd, STDERR_FILENO);
    }

    int rc = execlp("sh", "sh", "-c", command.c_str(), static_cast<char *>(0));
    if (rc == -1) {
        string msg = "Failed to execute " + command;
        perror(msg.c_str());
        exit(EX_OSERR);
    }
    exit(WEXITSTATUS(rc));
}

void Process::wait()
{
    if (state == STARTED) {
        int status;
        g_message("Waiting for %d", pid);
        int rc = waitpid(pid, &status, 0);
        if (rc == -1) {
            std::ostringstream msg;
            msg << "Failed to wait on pid " << pid << ": " << strerror(errno);
            throw std::runtime_error(msg.str());
        }
        state = FINISHED;
        exitStatus = WEXITSTATUS(status);
        g_message("Finished waiting for %d", pid);
    }
}

std::string Process::getLogPath() const
{
    return logPath;
}

int Process::getExitStatus()
{
    if (state != FINISHED) {
        wait();
    }

    return exitStatus;
}

int Process::getPid() const
{
    return pid;
}

Process::State Process::getState() const
{
    return state;
}

void Process::stop()
{
    if(state == STARTED) {
        wait();
    }
    if (logFD != -1) {
        close(logFD);
    }
}

int Process::kill(int signal)
{
    return ::kill(pid, signal);
}
