#include "my_string.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
    t_string *str1 = alloc_str_t_string(NULL);
    t_string *str2 = alloc_str_t_string("yo\n");
    t_string *str3_1 = alloc_str_t_string("hello ");
    t_string *str3_2 = alloc_str_t_string("there\n");
    t_string *str3 = concat_t_string(str3_1, str3_2);
    t_string *str4 = concat_t_string(str1, str2);
    t_string *str5 = alloc_str_t_string("toto tutu");

    // explain_t_string(str5);
    int result4 = remove_substr_t_string(str5, "o t");
    printf("replace_substr_t_string str5: %d\n", result4);
    // explain_t_string(str5);


    // print_string(str3);
    // print_string(str4);

    t_string *str_dup1 = dup_t_string(str1);
    printf("%p\n", str1);
    // explain_t_string(str1);
    // explain_t_string(str_dup1);
    t_string *str_dup3 = dup_t_string(str3);
    printf("%p\n", str3);
    // explain_t_string(str3);
    explain_t_string(str_dup3);
    int result1 = replace_char_t_string(str3, 'e', '0');
    printf("replace_char_t_string: %d\n", result1);
    explain_t_string(str3);
    int result2 = replace_substr_t_string(str3, "llo", "YOLO");
    printf("replace_substr_t_string: %d\n", result2);
    explain_t_string(str3);
    remove_substr_t_string(str3, "0");
    explain_t_string(str3);
    remove_substr_t_string(str3, "YOLO th");
    explain_t_string(str3);
    replace_substr_t_string(str3, "hr\n", "bonjour");
    explain_t_string(str3);
    int result3 = remove_substr_t_string(str5, "o");
    printf("replace_substr_t_string str5: %d\n", result3);
    // explain_t_string(str5);
    free_t_string(&str1);
    free_t_string(&str2);
    free_t_string(&str3);

    free_t_string(&str3_1);
    free_t_string(&str3_2);
    free_t_string(&str4);
    free_t_string(&str5);
    free_t_string(&str_dup1);
    free_t_string(&str_dup3);

    t_string **objs = va_alloc_str_t_string(3, "hello", "world", "!");
    for (int i = 0; i < 3; i++) {
        // explain_t_string(objs[i]);
        free_t_string(&objs[i]);
    }
    free(objs);

    return 0;
}
