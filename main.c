#include "my_string.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av) {
    t_string *str1 = alloc_str_t_string(NULL);
    t_string *str2 = alloc_str_t_string("yo\n");
    t_string *str3_1 = alloc_str_t_string("hello ");
    t_string *str3_2 = alloc_str_t_string("there");
    t_string *str3 = concat_t_string(str3_1, str3_2);
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
    int result = replace_char_t_string(str3, 'e', '0');
    printf("replace_char_t_string: %d\n", result);
    explain_t_string(str3);
    result = replace_substr_t_string(str3, "llo", "YOLO");
    printf("replace_substr_t_string: %d\n", result);
    explain_t_string(str3);
    free_t_string(&str1);
    free_t_string(&str2);
    free_t_string(&str3);
    free_t_string(&str3_1);
    free_t_string(&str3_2);
    free_t_string(&str4);
    return 0;
}