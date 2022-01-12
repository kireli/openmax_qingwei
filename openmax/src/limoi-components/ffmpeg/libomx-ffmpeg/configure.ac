AC_PREREQ(2.61)
AC_INIT([LIM ffmpeg OpenMax wrapper library], [0.0.3], [], [libomx-ffmpeg])
AM_INIT_AUTOMAKE

# CURRENT:REVISION:AGE
OMX_FFMPEG_SO_VERSION="0:0:0"
AC_SUBST(OMX_FFMPEG_SO_VERSION)

AC_CONFIG_SRCDIR([include/omx-ffmpeg.h])
AC_CONFIG_HEADER([config.h])

AC_CONFIG_FILES([
	Makefile
	libomx-ffmpeg.pc
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
PKG_CHECK_MODULES([LIMOI], [liblimoi-core])
PKG_CHECK_MODULES([LIMOIBASE], [liblimoi-base])
PKG_CHECK_MODULES([AVFORMAT], [libavformat])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

AC_OUTPUT
