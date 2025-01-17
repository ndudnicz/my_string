#include "../my_string.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* alloc_str_t_string */
void    test_alloc_str_t_string_null()
{
    const char  *MSG = "tests_my_string_alloc.test_alloc_str_t_string_null";
    bool        error = false;
    start_test(MSG);

    t_string    *str_null = alloc_str_t_string(NULL);
    bool test_value_null = test_assert(str_null->value == NULL, "str_null->value == NULL");
    error = !test_value_null;
    bool test_len_zero = test_assert(str_null->len == 0, "str_null->len == 0");
    error = error || !test_len_zero;
    free_t_string(&str_null);

    end_test(MSG, !error);
}

void    test_alloc_str_t_string_not_null()
{
    const char  *MSG = "tests_my_string_alloc.test_alloc_str_t_string_not_null";
    bool        error = false;
    start_test(MSG);

    const char      *str = "NOT NULL yo";
    const size_t    str_len = strlen(str);

    char *assert_message = NULL;
    asprintf(&assert_message, "str_not_null->value == \"%s\"", str);
    t_string    *str_not_null = alloc_str_t_string(str);
    bool test_value_not_null = test_assert(strcmp(str, str_not_null->value) == 0, assert_message);
    error = !test_value_not_null;
    free(assert_message);
    assert_message = NULL;
    asprintf(&assert_message, "str_not_null->len == %ld", str_len);
    bool test_len = test_assert(str_not_null->len == strlen(str), assert_message);
    error = error || !test_len;
    free_t_string(&str_not_null);

    end_test(MSG, !error);
}

/* alloc_param_t_string */
void    test_alloc_param_t_string_null()
{
    const char  *MSG = "tests_my_string_alloc.test_alloc_param_t_string_null";
    bool        error = false;
    start_test(MSG);

    t_string    *str_null = alloc_param_t_string('a', 0);
    bool test_value_null = test_assert(str_null->value == NULL, "str_null->value == NULL");
    error = !test_value_null;
    bool test_len_zero = test_assert(str_null->len == 0, "str_null->len == 0");
    error = error || !test_len_zero;
    free_t_string(&str_null);

    end_test(MSG, !error);
}

void    test_alloc_param_t_string_not_null()
{
    const char      *MSG = "tests_my_string_alloc.test_alloc_param_t_string_not_null";
    bool            error = false;
    start_test(MSG);

    const char      c = '.';
    const size_t    len = 42;
    char *const     str = malloc(sizeof(char) * (len + 1));

    for (size_t i = 0; i < len; i++)
        str[i] = c;

    char *assert_message = NULL;
    asprintf(&assert_message, "str_not_null->value == \"%s\"", str);
    t_string        *str_not_null = alloc_param_t_string(c, len);
    bool test_value_not_null = test_assert(strcmp(str, str_not_null->value) == 0, assert_message);
    error = !test_value_not_null;
    free(assert_message);
    assert_message = NULL;
    asprintf(&assert_message, "str_not_null->len == %ld", len);
    bool test_len = test_assert(str_not_null->len == strlen(str), assert_message);
    error = error || !test_len;
    free_t_string(&str_not_null);

    end_test(MSG, !error);
}

/* dup_t_string */
void    test_dup_t_string_null()
{
    const char  *MSG = "tests_my_string_alloc.test_dup_t_string_null";
    bool        error = false;
    start_test(MSG);

    t_string    *str_null = alloc_str_t_string(NULL);
    t_string    *str_null_dup = dup_t_string(str_null);
    bool test_value_null = test_assert(str_null_dup->value == NULL, "str_null_dup->value == NULL");
    error = !test_value_null;
    bool test_len_zero = test_assert(str_null_dup->len == 0, "str_null_dup->len == 0");
    error = error || !test_len_zero;
    free_t_string(&str_null);
    free_t_string(&str_null_dup);

    end_test(MSG, !error);
}

void    test_dup_t_string_not_null()
{
    const char  *MSG = "tests_my_string_alloc.test_dup_t_string_not_null";
    bool        error = false;
    start_test(MSG);

    const char      *str = "NOT NULL DUP";
    const size_t    len = strlen(str);

    char *assert_message = NULL;
    asprintf(&assert_message, "str_not_null_dup->value == \"%s\"", str);
    t_string    *str_not_null = alloc_str_t_string(str);
    t_string    *str_not_null_dup = dup_t_string(str_not_null);
    bool test_value_not_null = test_assert(strcmp(str, str_not_null_dup->value) == 0, assert_message);
    error = !test_value_not_null;
    free(assert_message);
    assert_message = NULL;
    asprintf(&assert_message, "str_not_null_dup->len == %ld", len);
    bool test_len = test_assert(str_not_null->len == strlen(str), assert_message);
    error = error || !test_len;
    free_t_string(&str_not_null);
    free_t_string(&str_not_null_dup);

    end_test(MSG, !error);
}

/* va_alloc_str_t_string */
void    test_va_alloc_str_t_string_null()
{
    const char  *MSG = "tests_my_string_alloc.test_va_alloc_str_t_string_null";
    bool        error = false;
    start_test(MSG);

    t_string    **array_null = va_alloc_str_t_string(0);
    bool test_value_null = test_assert(array_null == NULL, "array_null == NULL");
    error = !test_value_null;

    end_test(MSG, !error);
}

bool    test_va_array_values(t_string **array, char **values, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(array[i]->value, values[i]) != 0)
            return false;
    }
    return true;
}

void    test_va_alloc_str_t_string_not_null()
{
    const char  *MSG = "tests_my_string_alloc.test_va_alloc_str_t_string_not_null";
    bool        error = false;
    start_test(MSG);

    size_t  len = 5;
    char    *values[] = { "VA", "ALLOC", "STR", "T", "STRING" };

    t_string    **array = va_alloc_str_t_string(len, values[0], values[1], values[2], values[3], values[4]);
    bool test_alloc = test_assert(array != NULL, "array != NULL");
    error = !test_alloc;
    bool test_values = test_assert(test_va_array_values(array, values, len), "array values check");
    error = !test_values;
    for (size_t i = 0; i < len; i++)
        free_t_string(&array[i]);

    end_test(MSG, !error);
}

int     main()
{
    /* alloc_str_t_string */
    title("ALLOC_STR_T_STRING");
    test_alloc_str_t_string_null();
    test_alloc_str_t_string_not_null();
    /* alloc_param_t_string */
    title("ALLOC_PARAM_T_STRING");
    test_alloc_param_t_string_null();
    test_alloc_param_t_string_not_null();
    /* dup_t_string */
    title("DUP_T_STRING");
    test_dup_t_string_null();
    test_dup_t_string_not_null();
    /* va_alloc_str_t_string */
    title("VA_ALLOC_STR_T_STRING");
    test_va_alloc_str_t_string_null();
    test_va_alloc_str_t_string_not_null();
}