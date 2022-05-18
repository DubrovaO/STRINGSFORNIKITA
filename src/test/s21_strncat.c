#include <string.h>

#include "s21_string.h"

char *s21_strncat(char *dest, const char *str, s21_size_t n);

int main() {
    char str1[100] = "12345";
    const char str2[100] = "6789";
    char str3[100] = "12345";
    const char str4[100] = "6789";

    s21_size_t n = 1;

    s21_strncat(str1, str2, n);
    printf("%s\n", str1);

    strncat(str3, str4, n);
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
