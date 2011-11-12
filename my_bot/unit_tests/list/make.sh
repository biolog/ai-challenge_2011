#!/bin/bash

GCC_FLAGS="-Wall -g -O0"
SRC_DIR=../../src

gcc -o test_list -I$SRC_DIR $GCC_FLAGS \
        test_list.c \
        $SRC_DIR/list.c

