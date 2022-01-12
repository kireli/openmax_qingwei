AC_PREREQ(2.61)
AC_INIT([LIM utility], [0.1.2], [], [liblimutil])
AM_INIT_AUTOMAKE

# CURRENT:REVISION:AGE
LIMUTIL_SO_VERSION="0:0:0"
AC_SUBST(LIMUTIL_SO_VERSION)

AC_CONFIG_SRCDIR([include/limlog.h])
AC_CONFIG_HEADER([config.h])

AC_CONFIG_FILES([
	Makefile
	liblimutil.pc
	include/Makefile
	src/Makefile
	test/Makefile
])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

AM_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

AC_OUTPUT
