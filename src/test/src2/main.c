#include "s21_string.h"

int main() {
  char str[] = "1234567890";
  s21_memset(str, '+', 5);
  printf("%s\n", str);
  return 0;
}
