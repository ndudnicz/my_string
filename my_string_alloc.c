#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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

t_string    **va_alloc_str_t_string(int n, ...)
{
    t_string    **objs = malloc(sizeof(t_string*) * n);
    va_list     ap;

    va_start(ap, n);
    for (int i = 0; i < n; i++)
        objs[i] = alloc_str_t_string(va_arg(ap, const char*));
    va_end(ap);
    return objs;
}