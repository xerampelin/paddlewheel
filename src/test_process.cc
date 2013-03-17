#include <cstdlib>
#include <iostream>
#include <fstream>

#include <gtest/gtest.h>
#include <boost/signal.hpp>

#include "Process.h"

TEST(SimpleLaunch, SimpleLaunch)
{
    Process echo("echo 'hi'");
    EXPECT_STREQ("echo.log", echo.logName.c_str());

    /*
    int pid = echo.run();
    echo.wait();
        
    std::ifstream log(echo.getLogName());
    EXPECT_TRUE(log);

    std::string line;
    log >> line;
    EXPECT_STREQ(line, "hi");
    */
}

