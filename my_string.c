#include "my_string.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

t_string    *init_string(char *str) {
    t_string    *obj = (t_string*)malloc(sizeof(t_string));
    if (str == NULL || strlen(str) == 0) {
        obj->len = 0;
        obj->value = NULL;
    } else {
        obj->len = strlen(str);
        obj->value = strdup(str);
    }
    return obj;
}

void    free_string(t_string **obj) {
    free((*obj)->value);
    (*obj)->value = NULL;
    *obj = NULL;
}

int     print_string(t_string *obj) {
    return write(1, obj->value, obj->len);
}

int     explain_t_string(t_string *obj) {
    return printf("obj(%p): { len: %d, value(%p): '%s' }\n",
        obj, obj->len, obj->value, obj->value);
}

t_string    *concat_string(char *s1, char *s2) {
    const int s1len = strlen(s1);
    const int s2len = strlen(s2);
    if (s1 != NULL && s1len > 0 && s2 != NULL && s2len > 0)
        return init_string(strcat(s1, s2));
    else if (s1 && s1len > 0)
        return init_string(s1);
    else if (s2 && s2len > 0)
        return init_string(s2);
    else
        return init_string(NULL);
}

t_string    *concat_t_string(t_string *obj1, t_string *obj2) {
    if (obj1->value != NULL && obj1->len > 0 && obj2->value != NULL && obj2->len > 0)
           return init_string(strcat(obj1->value, obj2->value));
    else if (obj1->value && obj1->len > 0)
        return init_string(obj1->value);
    else if (obj2->value && obj2->value > 0)
        return init_string(obj2->value);
    else
        return init_string(NULL); 
}

t_string    *dup_t_string(t_string *obj) {
    return init_string(obj->value);
}