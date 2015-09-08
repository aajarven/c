#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


void print_array(char *buf, int *arr, int n)
{
    char b[8];
    strcpy(buf, "{ ");
    for (int i = 0; i < n; i++) {
        sprintf(b, "%d ", arr[i]);
        strcat(buf, b);
    }
    strcat(buf, "}");
}

START_TEST(test_array_sum) {
    int arr[8];
    for (int i = 0; i < 3; i++) {
        int len = rand() % 6 + 1;
        int mod = 0;
        for (int j = 0; j < len; j++) {
            arr[j] = rand() % 100;
            mod += arr[j];
        }
        int stu = array_sum(arr, len);
        char outbuf[100] = { 0 };
        print_array(outbuf, arr, len);
        fail_unless(stu == mod, "array_sum() called with array %s (length: %d). You returned: %d. Should have been: %d.",
                outbuf, len, stu, mod);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("arraySum");
	tmc_register_test(s, test_array_sum, "arraysum");
	return tmc_run_tests(argc, argv, s);
}
