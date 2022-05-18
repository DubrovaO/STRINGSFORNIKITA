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

/*int main() {
  char str1[20] = "abcdecfabc";
  int c = 'e';
  char* ret = s21_strchr(str1, c);
  printf("%s\n", ret);
  return 0;
}*/
