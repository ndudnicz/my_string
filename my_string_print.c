//
// Created by Nicolas Dudniczenko on 12/07/2024.
//

#include <unistd.h>
#include <stdio.h>

#include "my_string.h"

int     print_string(const t_string *obj)
{
    return write(1, obj->value, obj->len);
}

int     explain_t_string(const t_string *obj)
{
    return printf("obj(%p): { len: %d, value(%p): '%s' }\n",
                  obj, obj->len, obj->value, obj->value);
}