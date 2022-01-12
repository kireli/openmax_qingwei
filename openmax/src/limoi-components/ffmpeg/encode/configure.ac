AC_PREREQ(2.61)
AC_INIT([OpenMAX limoi ffmpeg encode component],
        [0.0.8], [], [limoi-ffmpeg-encode])
AM_INIT_AUTOMAKE

AC_CONFIG_HEADER([config.h])

AC_CONFIG_FILES([
	Makefile
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
PKG_CHECK_MODULES([OMX_FFMPEG], [libomx-ffmpeg])

AC_SUBST([limoicomponentdir], '[${libdir}/limoi/component]')
AC_SUBST([limoicomponent_ldflags], '[-module -avoid-version]')

PKG_CHECK_MODULES([AVCODEC], [libavcodec])
PKG_CHECK_MODULES([SWSCALE], [libswscale])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

AC_OUTPUT
