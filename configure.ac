AC_INIT([Paddlewheel], [0.1], [bren@ragh.us], [paddlewheel], [https://github.com/xerampelin/paddlewheel])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_PROG_CXX
AC_PROG_RANLIB
AC_LANG(C++)

PKG_CHECK_MODULES([GLIBMM], [glibmm-2.4 giomm-2.4])

AC_CHECK_HEADER([boost/filesystem.hpp], [],
                [AC_MSG_ERROR([Couldn't find boost/filesystem.hpp])])

AC_OUTPUT
