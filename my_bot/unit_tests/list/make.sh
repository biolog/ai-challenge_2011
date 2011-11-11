#!/bin/bash

SRC_DIR=../../src

gcc -o test_list -I$SRC_DIR \
        test_list.c \
        $SRC_DIR/list.c

