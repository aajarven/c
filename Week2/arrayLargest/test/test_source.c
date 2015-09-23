#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"

void print_array(char *buf, int *arr, int n) {
    char b[8];
    strcpy(buf, "{ ");
    for (int i = 0; i < n; i++) {
        sprintf(b, "%d ", arr[i]);
        strcat(buf, b);
    }
    strcat(buf, "}");
}

START_TEST(test_largest_num) {
    int arr[8];
    int kiint_arr[]={1,50,7,40,-1,100};
    if (largest_number(kiint_arr)>50)
      fail("You are either reading beyond the last value or modifying the values in the array.\n");

    for (int i = 0; i < 3; i++) {
        int len = rand() % 6 + 1;
        int mod = 0;
        for (int j = 0; j < len; j++) {
            arr[j] = rand() % 100;
            if (arr[j] > mod)
                mod = arr[j];
        }
        arr[len] = -1;
        int stu = largest_number(arr);
        char outbuf[100] = { 0 };
        print_array(outbuf, arr, len + 1);
        fail_unless(stu == mod, "[Task 2.4] largest_num() called with array %s. You returned: %d. Should have been: %d.",
                outbuf, stu, mod);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("arrayLargest");
	tmc_register_test(s, test_largest_num, "arrayLargest");
	return tmc_run_tests(argc, argv, s);
}
