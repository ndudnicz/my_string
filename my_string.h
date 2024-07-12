#ifndef __MY_STRING__
# define __MY_STRING__

typedef struct  my_string
{
    char    *value;
    int     len;
}               t_string;

t_string        *alloc_str_t_string(const char *str);
t_string        *alloc_param_t_string(char c, int len);
void            free_t_string(t_string **obj);
int             print_string(const t_string *obj);
t_string        *concat_string(const char *s1, const char *s2);
t_string        *concat_t_string(const t_string *s1, const t_string *s2);
t_string        *dup_t_string(const t_string *obj);
int             explain_t_string(const t_string *obj);
int             replace_char_t_string(const t_string *obj, char search, char replace);
int             replace_substr_t_string(t_string *obj, const char *search, const char *replace);

#endif