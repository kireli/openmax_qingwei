AC_PREREQ(2.61)
AC_INIT([OpenMAX limoi OGG decoder component], [0.0.7], [], [limoi-ogg_dec])
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

AC_SUBST([limoicomponentdir], '[${libdir}/limoi/component]')
AC_SUBST([limoicomponent_ldflags], '[-module -avoid-version]')

PKG_CHECK_MODULES([VORBIS], [vorbis], [with_vorbis=yes], [with_vorbis=no])
AM_CONDITIONAL([WITH_OGG_DEC], [test x$with_vorbis = xyes])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

AC_OUTPUT
