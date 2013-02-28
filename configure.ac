AC_INIT([Paddlewheel], [0.1], [bren@ragh.us], [paddlewheel], [http://github.com/])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if [ test -z "$DOXYGEN" ]; then
    AC_MSG_WARN([Could not find doxygen -- continuing without doxygen support.])
fi

AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])
AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile])])
