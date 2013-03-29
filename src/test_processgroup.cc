#include <fstream>

#include <gtest/gtest.h>

#include "ProcessGroup.h"

TEST(SimpleProcessGroup, basic)
{
    ProcessGroup pg(2);
    pg.add("echo 'hi'");
    pg.add("touch foo");
    pg.waitAll();

    std::ifstream in(pg[0]->getLogPath());
    std::string echoLog;
    in >> echoLog;

    ASSERT_STREQ("hi", echoLog.c_str());

    unlink("foo");
}
