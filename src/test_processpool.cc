#include <fstream>
#include <unistd.h>

#include <gtest/gtest.h>
#include <glibmm/iochannel.h>
#include <glibmm/ustring.h>

#include "ProcessPool.h"

#ifndef TEST_DATA_DIR
#define TEST_DATA_DIR "src/test-data"
#endif


std::string getTestDataDir()
{
    char const * testDataDir = getenv("TEST_DATA_DIR");
    if (!testDataDir) {
        testDataDir = TEST_DATA_DIR;
    }
    return testDataDir;
}

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

    ASSERT_EQ(echoLog, "hi");

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

    ASSERT_EQ(echoLog, "foo");

    pg[0]->kill();

    cleanup(pg);
}

TEST(FileProcessPool, basic)
{
    using namespace Glib;

    RefPtr <IOChannel> iochan(
            IOChannel::create_from_file(
                getTestDataDir() + "/FileProcessPool-basic.in",
                "r"));
    std::shared_ptr <ProcessPool> pool(ProcessPool::createFromFile(iochan));

    RefPtr <IOChannel> log(
            IOChannel::create_from_file(
                (*pool)[0]->getLogPath(), "r"));

    Glib::ustring logData;
    for (int i = 0; i < 5; i++) {
        log->read_line(logData);
        std::cout << "log file data: " << logData << std::endl;
    }

    ASSERT_EQ("foo", logData);
}
