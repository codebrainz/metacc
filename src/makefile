#
# Make file for Meta C lexer
#
# Copyright (c) 2012 Matthew Brush <mbrush@codebrainz.ca>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#   1. Redistributions of source code must retain the above copyright notice,
#      this list of conditions and the following disclaimer.
#   2. Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
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

#llvm_compile_flags := $(shell llvm-config --libs core jit native --cxxflags)
#llvm_link_flags := $(shell llvm-config --libs core jit native --ldflags)

compile_flags = $(CFLAGS) $(debug_flags) $(llvm_compile_flags)
link_flags = $(LDFLAGS) -ll -ly -lstdc++ $(llvm_link_flags)

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
	rm -f metacc gen-*.cc gen-*.hh *.oc *.occ *.ocpp
	rm -rf *.dSYM

# Future: install binary and related files

# Future: uninstall binary and related files

# Future: build a tarball for distribution

# Future: Delete this file and use Autotools

.PHONY: clean