bin_PROGRAMS = paddlewheel

noinst_PROGRAMS = $(TESTS)

common_sources = src/Options.cc

paddlewheel_SOURCES = src/paddlewheel.cc
paddlewheel_SOURCES += src/Process.cc
paddlewheel_SOURCES += src/ProcessPool.cc
paddlewheel_SOURCES += $(common_sources)

AM_CPPFLAGS =
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(GLIBMM_CFLAGS)
AM_CPPFLAGS += -I$(gtestheaders)
AM_CPPFLAGS += -I$(gtestdir)

LDADD =
LDADD += -lboost_signals
LDADD += -lboost_system
LDADD += -lboost_filesystem
LDADD += $(GLIBMM_LIBS)
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
test_process_SOURCES += $(common_sources)
test_process_LDADD = $(libgtestmain) $(libgtest) $(LDADD)
TESTS += test_process

test_processpool_SOURCES = src/test_processpool.cc
test_processpool_SOURCES += src/ProcessPool.cc
test_processpool_SOURCES += src/Process.cc
test_processpool_SOURCES += $(common_sources)
test_processpool_LDADD = $(libgtestmain) $(libgtest) $(LDADD)
TESTS += test_processpool
