#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_number_swap) {
    int a, b;

    for (int i = 0; i < 3; i++) {
        a = rand() % 100;
        b = rand() % 100;
        int a_temp = a;
        int b_temp = b;
        swap(&a, &b);
        fail_unless(a == b_temp && b == a_temp, "swap(a, b) called with *a = %d and *b = %d. Values after call are: a: %d (should be %d), b: %d (should be %d)",
                a_temp, b_temp, a, b_temp, b, a_temp);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("numberswap");
	tmc_register_test(s, test_number_swap, "numberswap");
	return tmc_run_tests(argc, argv, s);
}
