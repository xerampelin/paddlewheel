AC_INIT([Paddlewheel], [0.1], [bren@ragh.us], [paddlewheel], [https://github.com/xerampelin/paddlewheel])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
#AC_CONFIG_SUBDIRS([3rdparty/gtest-1.6.0])
AC_PROG_CXX
AC_PROG_RANLIB

PKG_CHECK_MODULES([GLIBMM], [glibmm-2.4 giomm-2.4])

AC_LANG(C++)
SAVED_LDFLAGS=$LDFLAGS
LDFLAGS="$LDFLAGS -lboost_signals"
AC_LINK_IFELSE(
               [AC_LANG_PROGRAM([#include <boost/signals.hpp>],
                                [boost::signal<void ()> sig;])],
                                [TEST_LIBS="$TEST_LIBS -lboost_signals"]
                                [HAVE_BOOST_SIGNALS=1],
                                [AC_MSG_WARN([libboost_signals is not installed.])])
LDFLAGS=$SAVED_LDFLAGS

AC_OUTPUT
