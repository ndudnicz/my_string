#include <string.h>

#include "my_string.h"

int    strcmp_t_string(const t_string *s1, const t_string *s2)
{
    return strcmp(s1->value, s2->value);
}