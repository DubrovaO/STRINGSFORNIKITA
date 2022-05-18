#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    char *str1 = (char *)str;
    while (n--) {
        *str1 = (char)c;
        str1++;
    }
    return str;
}
/*int main() {
    char str[] = "123456789";
    char str2[] = "123456789";
    s21_memset(str, '+', 5);
    printf("%s\n", str);
    memset(str2, '+', 5);
    printf("%s\n", str2);
    return 0;
}*/
