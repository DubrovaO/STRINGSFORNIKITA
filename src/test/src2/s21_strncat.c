#include <string.h>

#include "s21_string.h"

char *s21_strncat(char *dest, const char *str, s21_size_t n);

int main() {
    char str1[100] = "abcdefg";
    const char str2[100] = "hijk";
    size_t n = 3;

    s21_strncat(str1, str2, n);
    printf("%s\n", str1);

    strncat(str1, str2, n);
    printf("%s\n", str1);

    return 0;
}

char *s21_strncat(char *dest, const char *str, s21_size_t n) {
    char *start = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (n != 0) {
        *dest = *str;
        dest++;
        str++;
        n--;
    }
    return (start);
}
