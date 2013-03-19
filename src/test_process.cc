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
    Process touch("echo 'hello world'");
    int pid = touch.run();
    EXPECT_TRUE(pid > 0);
    touch.wait();
    EXPECT_TRUE(boost::filesystem::exists("echo.log"));
}

TEST(SimpleProcess, Empty)
{
    Process empty("");
    empty.run();
}
