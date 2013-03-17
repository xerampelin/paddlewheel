#include <string>
#include <vector>

#include "Process.h"

using std::string;
using std::vector;

/* Process is a class that runs a single process.  We'll start by defining
 * the main thing people want to do with this class--run a process.
 *
 * Most of the work will be handled by helper functions (explained shortly).
 * 
 * In the run method we will just fork and return, storing the child's pid along
 * the way.  The child will call exec and never return, but just in case we'll
 * also exit with an error after exec'ing.
 */
pid_t Process::run()
{
    pid = fork();
    if (pid == 0) {
        /* FIXME */
        exit(1);
    }
}

pid_t Process::wait()
{
}

string Process::generateLogName(Process::VecStr const & command)
{
    /* TODO check for command length */
    /* TODO change this to create a new file with appropriate extension if
     * others already exist. */
    return command[0] + ".log";
}

