#include "my_string.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av) {
    t_string *str1 = init_string(NULL);
    t_string *str2 = init_string("yo\n");
    t_string *str3 = concat_t_string(init_string("hello "), init_string("there"));
    t_string *str4 = concat_t_string(str1, str2);

    print_string(str3);
    print_string(str4);

    t_string *str_dup1 = dup_t_string(str1);
    printf("%p\n", str1);
    explain_t_string(str1);
    explain_t_string(str_dup1);
    t_string *str_dup3 = dup_t_string(str3);
    printf("%p\n", str3);
    explain_t_string(str3);
    explain_t_string(str_dup3);
    return 0;
}