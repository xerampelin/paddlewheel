#include <fstream>

#include <gtest/gtest.h>

#include "ProcessPool.h"

void cleanup(ProcessPool & pg)
{
    for (auto i = pg.begin(); i != pg.end(); ++i) {
        /* FIXME: kill the processes too */
        unlink((*i)->getLogPath().c_str());
    }
}

TEST(SimpleProcessPool, basic)
{
    ProcessPool pg(2);
    pg.add("echo 'hi'");
    pg.add("touch foo");
    pg.waitAll();

    std::ifstream in(pg[0]->getLogPath());
    std::string echoLog;
    in >> echoLog;

    ASSERT_STREQ("hi", echoLog.c_str());

    cleanup(pg);
}

TEST(SimpleProcessPool, concurrency)
{
    ProcessPool pg(2);
    pg.add("cat");
    pg.add("echo foo");
    pg[1]->wait();

    std::ifstream in(pg[1]->getLogPath());
    std::string echoLog;
    in >> echoLog;

    ASSERT_STREQ("foo", echoLog.c_str());

    pg[0]->kill();

    cleanup(pg);
}
