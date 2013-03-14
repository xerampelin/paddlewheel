bin_PROGRAMS = paddlewheel

noinst_PROGRAMS = $(TESTS)

paddlewheel_SOURCES = src/paddlewheel.cc

AM_CPPFLAGS =
AM_CPPFLAGS += -I$(gtestheaders)
AM_CPPFLAGS += -I$(gtestdir)

gtestdir = 3rdparty/gtest-1.6.0
gtestheaders = $(gtestdir)/include/
gtestldflags = -lpthread
libgtest = libgtest.a
libgtestmain= libgtest_main.a

noinst_LIBRARIES = 
noinst_LIBRARIES += libgtest.a
noinst_LIBRARIES += libgtest_main.a

libgtest_a_SOURCES = 
libgtest_a_SOURCES += $(gtestdir)/src/gtest.cc
libgtest_a_SOURCES += $(gtestdir)/src/gtest-filepath.cc
libgtest_a_SOURCES += $(gtestdir)/src/gtest-death-test.cc
libgtest_a_SOURCES += $(gtestdir)/src/gtest-port.cc
libgtest_a_SOURCES += $(gtestdir)/src/gtest-printers.cc
libgtest_a_SOURCES += $(gtestdir)/src/gtest-test-part.cc
libgtest_a_SOURCES += $(gtestdir)/src/gtest-typed-test.cc

libgtest_main_a_SOURCES = $(libgtest_a_SOURCES)
libgtest_main_a_SOURCES += $(gtestdir)/src/gtest_main.cc

TESTS =

test_launch_SOURCES = src/test_launch.cc
test_launch_LDADD = $(libgtestmain) $(libgtest)
test_launch_LDFLAGS = $(gtestldflags)
TESTS += test_launch

