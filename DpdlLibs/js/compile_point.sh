#!/bin/sh
echo "compiling point.c..."
export QUICKJS_INC=./quickjs
export QUICKJS_LIB=./quickjs
gcc -shared -o point.so -I$QUICKJS_INC -L$QUICKJS_LIB -lquickjs point.c
echo "done $?"
