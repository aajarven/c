#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_add_to_array) {
    for (int j = 0; j < 3; j++) {
        int size = rand() % 10 + 5;
        int *arr = malloc(size * sizeof(int));
        
        int tt[20];
        for (int i = 0; i < size; i++) {
            tt[i] = rand() % 100;
	    int *orig = arr;
            arr = add_to_array(orig, size + i, tt[i]);
            if (!arr) {
	      free(orig);
                fail("add_to_array returned NULL. Should have returned a pointer to allocated array.");
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (tt[i] != arr[i + size]) {
                free(arr);
                fail("array content incorrect after %dth add_to_array() call with value %d",
                        i+1, tt[i]);
            }
        }
	free(arr);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("AddToArray");
	tmc_register_test(s, test_add_to_array, "addtoarray");
	return tmc_run_tests(argc, argv, s);
}
