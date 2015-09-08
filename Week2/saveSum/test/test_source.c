#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_sum)
{
    int a = rand() % 50;
    int b = rand() % 50;
    int c = 0;
    int* ap = &a;
    int* bp = &b;
    int* cp = &c;
    saveSum(ap, bp, cp);
    fail_unless(c == a + b, "Sum should be %d, but it was %d", a + b, c);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("SaveSum");
	tmc_register_test(s, test_sum, "savesum");
	return tmc_run_tests(argc, argv, s);
}
