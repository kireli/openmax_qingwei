AC_PREREQ(2.61)
AC_INIT([LIM OpenMax demo resource manager], [0.0.2], [],
	      [lim-demo-resource-manager])
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

AC_SUBST([limresourcemanagerdir], '[${libdir}/limoi/resource-manager]')
AC_SUBST([limresourcemanager_ldflags], '[-module -avoid-version]')

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

AC_OUTPUT
