AC_PREREQ(2.61)
AC_INIT([OpenMAX limoi], [0.1.0], [], [liblimoi-core])
AM_INIT_AUTOMAKE

# CURRENT:REVISION:AGE
LIMOI_CORE_SO_VERSION="0:0:0"
AC_SUBST(LIMOI_CORE_SO_VERSION)

AC_CONFIG_SRCDIR([include/OMX_Core.h])
AC_CONFIG_HEADER([config.h])

AC_CONFIG_FILES([
	Makefile
	liblimoi-core.pc
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

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

# Checks for resource manager feature.
AC_ARG_ENABLE(
    [resource-manager],
    [AC_HELP_STRING(
        [--disable-resource-manager],
        [whether to disable resource manager compilation])],
    [with_resource_manager=$enableval],
    [with_resource_manager=yes])

# Conditionals
AM_CONDITIONAL([WITH_RESOURCE_MANAGER], [test x$with_resource_manager = xyes])

AC_OUTPUT
