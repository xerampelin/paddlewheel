#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include <gtest/gtest.h>
#include <boost/signal.hpp>
#include <boost/filesystem.hpp>

#include "Process.h"

TEST(SimpleProcess, BasicCase)
{
    unlink("echo.log");
    Process echo("echo 'hello world'");
    int pid = echo.run();
    EXPECT_TRUE(pid > 0);
    echo.wait();
    std::ifstream in("echo.log");
    std::string msg;
    std::getline(in, msg, '\n');
    EXPECT_STREQ("hello world", msg.c_str());
}

TEST(SimpleProcess, Empty)
{
    Process empty("");
    empty.run();
}
