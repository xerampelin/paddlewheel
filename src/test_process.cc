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
    unlink("basic-case-file");
    Process touch("touch basic-case-file");
    int pid = touch.run();
    EXPECT_TRUE(pid > 0);
    touch.wait();
    EXPECT_TRUE(boost::filesystem::exists("basic-case-file"));
}

TEST(SimpleProcess, Empty)
{
    Process empty("");
    empty.run();
}
