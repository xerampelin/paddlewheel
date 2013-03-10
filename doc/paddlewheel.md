NAME
----
paddlewheel - Runs multiple processes in parallel.

SYNOPSIS
--------
paddlewheel

DESCRIPTION
-----------
*paddlewheel* runs multiple processes in parallel.  Pipe in a bunch of commands,
one per line, and paddlewheel will execute them in parallel.  It will then tell
you which commands passed (exit with status 0) and which failed.  Log files will
also be generated with the output of the commands.

EXAMPLES
--------
ls tests/* | paddlewheel
    Run all the tests in the test directory.

ls *.txt | paddlewheel -e gzip 
