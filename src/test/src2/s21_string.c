#include "s21_string.h"

void* s21_memset(void* str, int c, s21_size_t n) {
    char* str1 = (char*)str;
    while (n--) {
        *str1 = (char)c;
        str1++;
    }
    return str;
}

char* s21_strcat(char* dest, const char* str) {
    char* start = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*str != '\0') {
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
    return (start);
}

char* s21_strchr(const char* str1, int c) {
    while (*str1 != '\0' && *str1 != c) {
        str1++;
    }
    if (*str1 == c) {
        return (char*)str1;
    }
    return s21_NULL;
}

char* s21_strncat(char* dest, const char* str, s21_size_t n) {
    char* start = dest;
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