#ifndef TESTS_H
#define TESTS_H
#include <stdbool.h>

bool    test_assert(bool condition, const char *msg);
void    start_test(const char *msg);
void    end_test(const char *msg, bool success);
void    title(const char *msg);


#endif //TESTS_H
