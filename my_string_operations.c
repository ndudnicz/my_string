#include "my_string.h"
#include <stdlib.h>
#include <string.h>

void    free_t_string(t_string **obj)
{
    free((*obj)->value);
    (*obj)->value = NULL;
    free(*obj);
    *obj = NULL;
}

t_string    *concat_string(const char *s1, const char *s2)
{
    const int s1len = strlen(s1);
    const int s2len = strlen(s2);
    if (s1 != NULL && s1len > 0 && s2 != NULL && s2len > 0)
        return alloc_str_t_string(strcat((char*)s1, (char*)s2));
    if (s1 && s1len > 0)
        return alloc_str_t_string(s1);
    if (s2 && s2len > 0)
        return alloc_str_t_string(s2);
    return alloc_str_t_string(NULL);
}

t_string    *concat_t_string(const t_string *obj1, const t_string *obj2)
{
    if (obj1->value != NULL && obj1->len > 0 && obj2->value != NULL && obj2->len > 0)
        return alloc_str_t_string(strcat(obj1->value, obj2->value));
    if (obj1->value && obj1->len > 0)
        return alloc_str_t_string(obj1->value);
    if (obj2->value && obj2->value > 0)
        return alloc_str_t_string(obj2->value);
    return alloc_str_t_string(NULL);
}

// replace the char search with replace in obj->value
// return the number of replacements
int     replace_char_t_string(const t_string *obj, const char search, const char replace)
{
    if (obj->len == 0)
        return 0;
    int count = 0;
    for (int i = 0; i < obj->len; i++) {
        if (obj->value[i] == search) {
            obj->value[i] = replace;
            count++;
        }
    }
    return count;
}

// replace the substr search with replace in obj->value
// return the number of replacements
int     replace_substr_t_string(t_string *obj, const char *search, const char *replace)
{
    if (obj->len == 0)
        return 0;
    int count = 0;
    const int search_len = strlen(search);
    const int replace_len = strlen(replace);
    for (int i = 0; i < obj->len; i++) {
        if (strncmp(obj->value + i, search, search_len) == 0) {
            obj->value = realloc(obj->value, obj->len + replace_len - search_len);
            memmove(obj->value + i + replace_len, obj->value + i + search_len, obj->len - i - search_len);
            memcpy(obj->value + i, replace, replace_len);
            obj->len += replace_len - search_len;
            count++;
        }
    }
    return count;
}