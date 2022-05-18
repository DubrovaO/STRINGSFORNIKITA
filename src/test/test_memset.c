/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "memset.check" instead.
 */

#include <check.h>

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(memset1)
{
char str1[100] = "123456789";
char str2[100] = "Nice";
char str3[100] = "000000";
char str4[100] = "-1-2-3-4-5";
char str5[100] = " ";
int c = '+';
ck_assert_str_eq(s21_memset(str1, c, 5),memset(str1, c, 5));
ck_assert_str_eq(s21_memset(str2, c, 2),memset(str2, c, 2));
ck_assert_str_eq(s21_memset(str3, c, 10),memset(str3, c, 10));
ck_assert_str_eq(s21_memset(str4, c, 0),memset(str4, c, 0));
ck_assert_str_eq(s21_memset(str5, c, 1),memset(str5, c, 1));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, memset1);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}