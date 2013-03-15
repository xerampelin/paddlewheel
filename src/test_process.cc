#include <cstdlib>

#include <gtest/gtest.h>
#include <boost/signal.hpp>

#include "Process.h"

TEST(SimpleLaunch, SimpleLaunch)
{
    Process ls("ls");

    int pid = ls.run();
    ls.wait();
        
    EXPECT_EQ(pid, -1);
}

