#!/bin/sh
mkdir -p bin
touch bin/.keep

gcc tests.c tests_my_string_alloc.c ../libstring.a -o bin/test_my_string_alloc && ./bin/test_my_string_alloc
