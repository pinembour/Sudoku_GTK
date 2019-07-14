#!/bin/bash
gcc -Wall sudoku.c tables.c itoa.c -o sudoku `pkg-config --cflags --libs glib-2.0 gtk+-2.0`
