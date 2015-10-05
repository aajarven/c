#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/tools.h"


START_TEST(test_sum) {
#ifdef SWAP
    int num1 = 1;
    int num2 = 2;
    SWAP(int, num1, num2);
    ck_assert_msg(num1 == 2 && num2 == 1, "1 and 2 should be 2 and 1 after swap, but it was %d and %d", num1, num2);
#else
    fail("Implement SWAP macro first");
#endif
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_sum, "26");
	return tmc_run_tests(argc, argv, s);
}
