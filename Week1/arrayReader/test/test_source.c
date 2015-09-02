#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_array_reader) {
    char inp[200];
    int size = rand() % 10 + 5;
    inp[0] = 0;
    int s_arr[20];
    int ar1[20];
    int i, ret;
    for (i = 0; i < size; i++) {
        s_arr[i] = rand() % 100;
        char buf[10];
        sprintf(buf, "%d ", s_arr[i]);
        strcat(inp, buf);
    }
    strcat(inp, "f");

    FILE *mock_input = freopen("mockinput", "w+", stdin);
    fputs(inp, mock_input);
    fseek(mock_input, 0, SEEK_SET);

    memset(ar1, 0, sizeof (ar1));
    ret = array_reader(ar1, 20);

    fail_unless(ret == size, "Wrong return value with input \"%s\". You returned %d, expected %d\n",
            inp, ret, size);

    for (i = 0; i < size; i++) {
        fail_unless(ar1[i] == s_arr[i], "Wrong array member with input \"%s\". You had %d as %dth item, expected %d\n",
                inp, ar1[i], i + 1, s_arr[i]);
    }

    fail_unless(ar1[size] == 0, "You have written more than %d values to array, which was the length of user input\n",
            size);
}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("arrayReader");
	tmc_register_test(s, test_array_reader, "arrayReader");
	return tmc_run_tests(argc, argv, s);
}
