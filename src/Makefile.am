bin_PROGRAMS = metacc

autogen_sources = gen-scanner.cc gen-parser.cc gen-parser.hh

metacc_SOURCES = main.cpp ast.h parser.h $(autogen_sources)
#metacc_LDFLAGS = $(LEXLIB)

gen-scanner.cc: metac-scanner.l gen-parser.hh
	$(LEX) -o $@ $<

gen-parser.hh: gen-parser.cc

gen-parser.cc: metac-parser.y
	$(YACC) -o $@ $<
