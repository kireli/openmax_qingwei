AC_PREREQ(2.61)
AC_INIT([OpenMAX limoi-base], [0.1.4], [], [liblimoi-base])
AM_INIT_AUTOMAKE

# CURRENT:REVISION:AGE
LIMOI_BASE_SO_VERSION="0:0:0"
AC_SUBST(LIMOI_BASE_SO_VERSION)

AC_CONFIG_SRCDIR([include/limoi.h])
AC_CONFIG_HEADER([config.h])

AC_CONFIG_FILES([
	Makefile
	liblimoi-base.pc
	include/Makefile
	src/Makefile
	test/Makefile
])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

AM_PROG_LIBTOOL

# Checks for libraries.
PKG_PROG_PKG_CONFIG()
PKG_CHECK_MODULES([LIMUTIL], [liblimutil])
PKG_CHECK_MODULES([LIMOI], [liblimoi-core])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

AC_OUTPUT
