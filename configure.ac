AC_PREREQ([2.59])

# Initialize build system tools
AC_INIT([metacc], [0.01], [mbrush@codebrainz.ca])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([src/metac-config.h])
AM_INIT_AUTOMAKE([1.10 -Wall -Werror foreign])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

# Check for utilities
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LEX
AC_PROG_YACC

# Generate build files
AC_CONFIG_FILES([
    Makefile
	src/Makefile
])
AC_OUTPUT

