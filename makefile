#
# Make file for Meta C lexer
#

CC = cc
LEX = flex
LCFLAGS = $(CFLAGS) -g -Wall
LLDFLAGS = $(LDFLAGS) -ll

metac-lexer: main.c lexer.c token.c scanner.c 
	$(CC) -o $@ $(LCFLAGS) $^ $(LLDFLAGS)

scanner.c: metac.l 
	$(LEX) -o $@ --header-file=scanner.h $<

clean:
	rm -f metac-lexer scanner.[ch]
	rm -rf *.dSYM
	