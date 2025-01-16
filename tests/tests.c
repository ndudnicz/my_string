#include <stdbool.h>
#include <stdio.h>

void    title(char *msg)
{
    printf("\033[1;33m%s\033[0m\n",  msg);
}

void    start_test(const char *msg)
{
    printf("Starting tests : %s\n", msg);
}

void    end_test(const char *msg, bool success)
{
    printf("Tests done %s : %s\n\n", success ? "✅" : "❌ with errors", msg);
}

bool    test_assert(bool condition, const char *msg)
{
    if (!condition)
    {
        printf("\033[1;31mAssert failed: %s\033[0m\n", msg);
    }
    else
    {
        printf("\033[1;32mAssert passed: %s\033[0m\n", msg);
    }
    return condition;
}