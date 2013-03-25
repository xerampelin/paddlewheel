bin_PROGRAMS = paddlewheel

noinst_PROGRAMS = $(TESTS)

paddlewheel_SOURCES = src/paddlewheel.cc
paddlewheel_SOURCES += src/Process.cc
paddlewheel_SOURCES += src/ProcessGroup.cc

AM_CPPFLAGS =
AM_CPPFLAGS += -I$(gtestheaders)
AM_CPPFLAGS += -I$(gtestdir)

LDADD =
LDADD += -lboost_signals
LDADD += -lboost_system
LDADD += -lboost_filesystem

gtestdir = $(srcdir)/3rdparty/gtest-1.6.0
gtestheaders = $(gtestdir)/include/
libgtest = libgtest.a -lpthread
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

test_process_SOURCES = src/test_process.cc src/Process.cc
test_process_LDADD = $(libgtestmain) $(libgtest) $(LDADD)
TESTS += test_process

test_processgroup_SOURCES = src/test_processgroup.cc
test_processgroup_SOURCES += src/ProcessGroup.cc
test_processgroup_SOURCES += src/Process.cc
test_processgroup_LDADD = $(libgtestmain) $(libgtest) $(LDADD)
TESTS += test_processgroup
