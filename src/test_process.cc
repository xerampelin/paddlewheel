#include <cstdlib>
#include <iostream>
#include <fstream>

#include <gtest/gtest.h>
#include <boost/signal.hpp>

#include "Process.h"

TEST(SimpleProcess, BasicCase)
{
    Process echo("echo 'Hello from test: SimpleProcess, BasicCase'");
    int pid = echo.run();
    echo.wait();
}

TEST(SimpleProcess, Empty)
{
    Process empty("");
    empty.run();
}
