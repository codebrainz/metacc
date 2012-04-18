#
# Make file for Meta C lexer
#

#------------------------------------#
# Utilities and Variable definitions #
#------------------------------------#

ifndef CC
  CC = clang
endif

ifndef CXX
  CXX = clang
endif

ifndef LEX
  LEX = flex
endif

ifndef YACC
  YACC = bison
endif

ifdef DEBUG
	debug_flags = -g -Wall -Werror -Wextra -Wno-unused-parameter -UNDEBUG -DEBUG=1
else
	debug_flags = -O2 -DNDEBUG=1 -UDEBUG
endif

compile_flags = $(CFLAGS) $(debug_flags)
link_flags = $(LDFLAGS) -ll -ly -lstdc++

# Plain C
c_sources = $(wildcard *.c)
c_objects = $(c_sources:.c=.oc)

# Normal C++
cpp_sources = $(wildcard *.cpp)
cpp_objects = $(cpp_sources:.cpp=.ocpp)

# Generated C/C++
cc_sources = gen-parser.cc gen-scanner.cc
cc_objects = $(cc_sources:.cc=.occ)


#--------------------------#
# Compilation and linking  #
#--------------------------#

# Link objects together (implicit first/default rule)
metacc: $(c_objects) $(cpp_objects) $(cc_objects)
	$(CC) -o $@ $^ $(link_flags)

# Compile all the sources into objects
%.oc: %.c
	$(CC) -c $(compile_flags) -o $@ $<

%.ocpp: %.cpp
	$(CXX) -c $(compile_flags) -o $@ $<

%.occ: %.cc
	$(CXX) -c $(compile_flags) -o $@ $<

#-------------------#
# Generated sources #
#-------------------#

# Flex scanner/tokenizer
gen-scanner.cc: metac-scanner.l
	$(LEX) -o $@ $<

# Bison parser heaser
gen-parser.hh: gen-parser.cc
#   do nothing, just declare dependency

# Bison parser source code
gen-parser.cc: metac-parser.y
	$(YACC) -o $@ $<

#-------------#
# Other stuff #
#-------------#

# Clean built files
clean:
	rm -f metac-lexer gen-*.cc gen-*.hh *.oc *.occ *.ocpp
	rm -rf *.dSYM

# Future: install binary and related files

# Future: uninstall binary and related files

# Future: build a tarball for distribution

# Future: Delete this file and use Autotools

.PHONY: clean