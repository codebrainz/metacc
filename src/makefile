#
# Make file for Meta C lexer
#

CC = g++
LEX = flex
YACC = bison

ifdef DEBUG
	debug_flags = -g -Wall -Werror -Wextra -Wno-unused-parameter -UNDEBUG -DEBUG=1
else
	debug_flags = -O2 -DNDEBUG=1 -UDEBUG
endif

ifdef CFLAGS
	compile_flags = $(CFLAGS)
else
	compile_flags =
endif

ifdef LDFLAGS
	link_flags = $(LDFLAGS) -ll -ly
else
	link_flags = -ll -ly
endif

sources = $(wildcard *.cpp) gen-scanner.cpp gen-parser.cpp
headers = $(wildcard *.h) gen-parser.hpp

metacc: $(sources) $(headers)
	$(CC) $(debug_flags) -o $@ $(compile_flags) $^ $(link_flags)

gen-scanner.cpp: metac-scanner.l
	$(LEX) -o $@ $<

gen-parser.hpp: gen-parser.cpp

gen-parser.cpp: metac-parser.y
	$(YACC) -o $@ $<

clean:
	rm -f metac-lexer gen-*.cpp gen-*.hpp *.o
	rm -rf *.dSYM

.PHONY: clean