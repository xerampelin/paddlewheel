gtestdir = 3rdparty/gtest-1.6.0
gtestheaders = $(gtestdir)/include/
gtestldflags = -lpthread
libgtest = $(gtestdir)/libgtest.a
libgtestmain= $(gtestdir)/libgtest_main.a
SUBDIRS = $(gtestdir)

bin_PROGRAMS = paddlewheel

noinst_PROGRAMS = $(TESTS)

paddlewheel_SOURCES = src/paddlewheel.cc

TESTS =

test_launch_SOURCES = src/test_launch.cc
test_launch_LDADD = $(libgtestmain) $(libgtest)
test_launch_LDFLAGS = $(gtestldflags)
test_launch_CPPFLAGS = -I$(gtestheaders)
TESTS += test_launch

