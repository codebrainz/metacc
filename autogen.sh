#!/bin/sh
autoreconf -vfi || exit 1
./configure $@  || exit 2
exit 0
