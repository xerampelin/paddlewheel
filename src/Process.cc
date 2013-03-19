#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
    if(command.length() == 0)
        return -1;


    pid = fork();
    if (pid == 0) {
        vector<string> argv;
        boost::split(argv, command, ::isspace);

        if (argv.size() > 0) {
            string logFile = argv[0] + ".log";
            
            int permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
            int fd = open(logFile.c_str(),
                          O_WRONLY | O_CREAT | O_TRUNC,
                          permissions);
            if (fd < 0) {
                string msg = "Error opening " + logFile;
                perror(msg.c_str());
            }

            dup2(STDOUT_FILENO, fd);
        }

        /* TODO use exec instead */
        int rc = system(command.c_str());
        /* TODO do something more useful with error case here. */
        if (rc != 0) {
            perror("system failed");
        }
        exit(1);
    }

    return pid;
}

pid_t Process::wait()
{
    int status;
    waitpid(pid, &status, 0);
}

