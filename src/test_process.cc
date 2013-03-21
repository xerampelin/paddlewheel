#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sysexits.h>

#include <gtest/gtest.h>
#include <boost/signal.hpp>
#include <boost/filesystem.hpp>

#include "Process.h"

std::string runWaitReadLine(Process & proc)
{
    int pid = proc.run();
    EXPECT_TRUE(pid > 0);
    proc.wait();
    std::ifstream in(proc.getLogPath().c_str());
    std::string msg;
    std::getline(in, msg, '\n');
    return msg;
}

TEST(SimpleProcess, BasicCase)
{
    Process echo("echo 'hello world'");
    std::string msg(runWaitReadLine(echo));
    EXPECT_STREQ("hello world", msg.c_str());
    EXPECT_EQ(EXIT_SUCCESS, echo.getStatus());
    unlink(echo.getLogPath().c_str());
}

void testEmptyish(std::string const & emptyish)
{
    Process empty(emptyish.c_str());
    std::string output(runWaitReadLine(empty));
    EXPECT_STREQ("", output.c_str());
    EXPECT_EQ(EXIT_SUCCESS, empty.getStatus());
    unlink(empty.getLogPath().c_str());
}

TEST(SimpleProcess, Empty)
{
    testEmptyish("");
    testEmptyish(" ");
    testEmptyish("\t ");
    testEmptyish("\n \n");
    testEmptyish("\n                                     \t\t\t\t\t");
}

