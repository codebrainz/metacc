#
# TODO: ANTLR generated sources not getting included in dist
#

bin_PROGRAMS = metacc

autogen_sources = \
	MetaCLexer.c \
	MetaCLexer.h \
	MetaCParser.c \
	MetaCParser.h

metacc_SOURCES = \
	main.c \
	$(autogen_sources)

metacc_CPPFLAGS = -I$(top_srcdir)/antlr
metacc_LDFLAGS = $(top_builddir)/antlr/libantlr3c.la

MetaCLexer.h: MetaCLexer.c

MetaCLexer.c: MetaCParser.h

MetaCParser.h: MetaCParser.c

MetaCParser.c: MetaC.g
	$(JAVA) -jar $(top_srcdir)/antlr/antlr-3.4-complete.jar $<

EXTRA_DIST = MetaC.g $(autogen_sources)
