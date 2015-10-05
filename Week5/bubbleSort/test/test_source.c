#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_bubblesort) {

    int numbers[] = {7, 2, 5, 9, 1};
    int sortedNumbers[] = {1, 2, 5, 7, 9};
    int reverseNumbers[] = {9, 7, 5, 2, 1};
    int count = sizeof(numbers)/sizeof(numbers[0]);
    int* sorted = bubble_sort(numbers, count, sorted_compare);
    ck_assert_msg(memcmp(sorted, sortedNumbers, count) == 0, "Sorting doesn't work correctly.");
    int* reverseSorted = bubble_sort(numbers, count, reverse_compare);
    ck_assert_msg(memcmp(reverseSorted, reverseNumbers, count) == 0, "Sorting doesn't work correctly.");

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_bubblesort, "1");
	return tmc_run_tests(argc, argv, s);
}
