#include <string.h>

#include "s21_string.h"

char* s21_strchr(const char* str1, int c) {
    while (*str1 != '\0' && *str1 != c) {
        str1++;
    }
    if (*str1 == c) {
        return (char*)str1;
    }
    return s21_NULL;
}

int main() {
    char str1[20] = "";
    int c = 'f';
    char str2[20] = "";
    int d = 'f';

    char* ret = s21_strchr(str1, c);
    printf("%s\n", ret);

    char* ret2 = strchr(str2, d);
    printf("%s\n", ret2);

    return 0;
}
