#
# Make file for Meta C lexer
#

CC = cc
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

sources = $(wildcard *.c) gen-scanner.c gen-parser.c
headers = $(wildcard *.h) gen-parser.h

metacc: $(sources) $(headers)
	$(CC) $(debug_flags) -o $@ $(compile_flags) $^ $(link_flags)

gen-scanner.c: metac-scanner.l
	$(LEX) -o $@ $<

gen-parser.h: gen-parser.c

gen-parser.c: metac-parser.y
	$(YACC) -o $@ $<

clean:
	rm -f metac-lexer gen-*.[ch] *.o
	rm -rf *.dSYM

.PHONY: clean