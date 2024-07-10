#ifndef __MY_STRING__
# define __MY_STRING__

typedef struct my_string
{
    char    *value;
    int     len;
} t_string;

t_string    *init_string(char *str);
void    free_string(t_string **obj);
int     print_string(t_string *obj);
t_string    *concat_string(char *s1, char *s2);
t_string    *concat_t_string(t_string *s1, t_string *s2);
t_string    *dup_t_string(t_string *obj);
int    explain_t_string(t_string *obj);

#endif