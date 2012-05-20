MetaC Compiler
=============

This is the testbed for the compiler for the new MetaC programming language.

Dependencies
-----------

In order to fully compile the MetaC compiler, you'll need at least the
following:

* GCC
* Autotools
* Libtool
* Java

For example on Ubuntu, you would run the following:

    $ sudo apt-get install build-essential libtool default-jre

__Note:__

The MetaC compiler does not itself depend on the Java runtime, but it uses the
Java program ANTLR to generate the target C lexer/parser code. In the future,
it will not be required at all, except in "maintainer mode". The ANTLR C runtime
that the compiler uses is compiled directly in so that the target machine isn't
required to have it installed.

Installation
-----------

To compile and install the MetaC compiler, run the following commands:

    $ ./configure
    $ make
    $ sudo make install

To see if the compiler is installed check the output of the following command:

    $ which metacc

The result should be something like:

    /usr/local/bin/metacc

Running
------

You can invoke the compiler on your source files as such:

    $ metacc -o mybin main.mc [...]

Where `mybin` is the output binary, `main.mc` is the MetaC source file with
the `main` entry point function and `[...]` is zero or more source files.
