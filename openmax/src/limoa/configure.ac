AC_PREREQ(2.61)
AC_INIT([OpenMAX limoa], [0.1.1], [], [liblimoa])
AM_INIT_AUTOMAKE

# CURRENT:REVISION:AGE
LIMOA_SO_VERSION="0:0:0"
AC_SUBST(LIMOA_SO_VERSION)

AC_CONFIG_SRCDIR([include/OpenMAXAL.h])
AC_CONFIG_HEADER([config.h])

AC_CONFIG_FILES([
	Makefile
	liblimoa.pc
	include/Makefile
	src/Makefile
	src/common/Makefile
	src/frontend/Makefile
	src/backend/Makefile
	test/Makefile
])

# additional user configurable options
## build limox as a background service
AC_ARG_ENABLE(
    [limox],
    [AC_HELP_STRING(
        [--enable-limox],
        [enable limox compilation as backend [default=no]])],
    [with_limox=$enableval],
    [with_limox=no])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

AM_PROG_LIBTOOL

# Checks for libraries.
PKG_PROG_PKG_CONFIG()
PKG_CHECK_MODULES([LIMUTIL], [liblimutil])

AC_ARG_WITH(omxil,
	[AS_HELP_STRING([--with-omxil=<omxil>],
	[name of OpenMAX IL implementation.])],
	[omxil_name=$with_omxil],
	[omxil_name=limoi]
)

# limoi components require liblimoi-base.
if test x"${omxil_name}" = xlimoi
then
PKG_CHECK_MODULES([OMXIL], [liblimoi-core, liblimoi-base])
else
PKG_CHECK_MODULES([OMXIL], [lib${omxil_name}])
fi

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

# Conditionals
AM_CONDITIONAL([WITH_LIMOX], [test x$with_limox = xyes])

AC_OUTPUT
