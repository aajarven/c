#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_digits) {
    ck_assert_msg(reverse_digits(8476) == 6748, "When reversing 8476, the right output is 6748, but your function returned %d\n", reverse_digits(8476));
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("reverseDigits");
	tmc_register_test(s, test_digits, "reverseDigits");
	return tmc_run_tests(argc, argv, s);
}
