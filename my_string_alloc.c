//
// Created by Nicolas Dudniczenko on 12/07/2024.
//

#include <stdlib.h>
#include <string.h>

#include "my_string.h"

t_string    *alloc_str_t_string(const char *str)
{
    t_string    *obj = malloc(sizeof(t_string));
    if (str == NULL || strlen(str) == 0) {
        obj->len = 0;
        obj->value = NULL;
    } else {
        obj->len = strlen(str);
        obj->value = strdup(str);
    }
    return obj;
}

t_string    *alloc_param_t_string(const char c, const int len)
{
    t_string    *obj = malloc(sizeof(t_string));
    obj->value = (char*)malloc(sizeof(char) * len);
    obj->len = len;
    for (int i = 0; i < len; i++)
        obj->value[i] = c;
    return obj;
}

t_string    *dup_t_string(const t_string *obj)
{
    return alloc_str_t_string(obj->value);
}