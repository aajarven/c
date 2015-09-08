#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "../src/source.h"



void pr_array(char *buf, int *arr, int n)
{
    char b[40];
    sprintf(buf, "{");
    while (n--) {
        sprintf(b, "%d", *arr++);
        if (n)
            strcat(b, ", ");
        strcat(buf, b);
    }
    strcat(buf, "}");
}


START_TEST(test_remove_substr)
{
    char *str[] = { "one two one twotwo three", "abcdefghijk", "ttatamtammtammitammi", "a b a b b b c d" };
    char *sub[] = { "two", "kkk", "tammi", "b" };
    char *ans[] = { "one  one  three", "abcdefghijk", "ttatamtamm", "a  a    c d" };
    
    for (int i = 0; i < 4; i++) {
        char work[30];
        memset(work, 0, 30);
        strcpy(work, str[i]);
        remove_substr(work, sub[i]);
        if (strcmp(work, ans[i])) {
            fail("[Task 2.8] remove_substr(\"%s\", \"%s\") should change the string to \"%s\". Your string: \"%s\".",
                    str[i], sub[i], ans[i], work);
        }
    }
}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
    Suite *s = suite_create("removeSubstring");

    tmc_register_test(s, test_remove_substr, "removeSubstring");
    
    return tmc_run_tests(argc, argv, s);
}
