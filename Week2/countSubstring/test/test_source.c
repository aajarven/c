#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "../src/source.h"


START_TEST(test_count_substr) {
    char *str[] = { "one two one twotwo three", "abcdefghijk", "ttatamtammtammitammi", "a b a b b b c d" };
    char *sub[] = { "two", "kkk", "tammi", "b" };
    int ans[] = { 3, 0, 2, 4 };
    
    for (int i = 0; i < 4; i++) {
        int stu = count_substring(str[i], sub[i]);
        fail_unless(stu == ans[i],
                "[Task 2.7] count_substr(\"%s\", \"%s\") should have returned %d. You returned %d.",
                str[i], sub[i], ans[i], stu);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("countSubstring");
	tmc_register_test(s, test_count_substr, "countsubstring");
	return tmc_run_tests(argc, argv, s);
}
