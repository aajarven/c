#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "../src/source.h"


START_TEST(test_count_alpha) {
    char str[20];
    for (int i = 0; i < 3; i++) {
        int count = 0;
        unsigned int len = rand() % 10 + 4;
        for (unsigned int j = 0; j < len; j++) {
            int c = rand() % 90 + 32;
            if (isalpha(c))
                count++;
            str[j] = c;
        }
        str[len] = 0;
        int stu = count_alpha(str);
        fail_unless(stu == count, "There are %d alpha characters in string '%s'. You returned: %d",
                count, str, stu);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("countAlpha");
	tmc_register_test(s, test_count_alpha, "countalpha");
	return tmc_run_tests(argc, argv, s);
}
