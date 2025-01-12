cmake_minimum_required(VERSION 3.28)
project(my_string C)

set(CMAKE_C_STANDARD 11)

add_executable(my_string main.c
        my_string_alloc.c
        my_string_cmp.c
        my_string_operations.c
        my_string_print.c
)
