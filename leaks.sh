#!/bin/sh
make && gcc main.c libstring.a && leaks -atExit -- ./a.out
