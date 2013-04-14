#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sysexits.h>

#include <gtest/gtest.h>

#include "Process.h"

std::string runWaitReadLine(Process & proc)
{
    EXPECT_TRUE(proc.getPid() > 0);
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
    ASSERT_STREQ("hello world", msg.c_str());
    ASSERT_EQ(EXIT_SUCCESS, echo.getExitStatus());
    unlink(echo.getLogPath().c_str());
}

void testEmptyish(std::string const & emptyish)
{
    Process empty(emptyish.c_str());
    std::string output(runWaitReadLine(empty));
    ASSERT_STREQ("", output.c_str());
    ASSERT_EQ(EXIT_SUCCESS, empty.getExitStatus());
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

TEST(SimpleProcess, Failure)
{
    Process badls("ls /foobizzle/aamMre2/JJmmmsdr389/JJiqqxmow");
    ASSERT_NE(EXIT_SUCCESS, badls.getExitStatus());
    unlink(badls.getLogPath().c_str());
}

TEST(SimpleProcess, NoopWait)
{
    Process ls("ls");
    ASSERT_EQ(EXIT_SUCCESS, ls.getExitStatus());
    ls.wait();
    ls.wait();
    ls.wait();
    unlink(ls.getLogPath().c_str());
}
