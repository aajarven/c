#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_dyn_reader) {
    for (int j = 0; j < 3; j++) {
        char inp[200];
        int size = rand() % 10 + 5;
        inp[0] = 0;
        int s_arr[20];
        int i;
        for (i = 0; i < size; i++) {
            s_arr[i] = rand() % 100;
            char buf[10];
            sprintf(buf, "%d ", s_arr[i]);
            strcat(inp, buf);
        }

        FILE *mock_input = freopen("mockinput", "w+", stdin);
        fputs(inp, mock_input);
        fseek(mock_input, 0, SEEK_SET);

        int *res = dynamic_reader(size);
        if (res == NULL) {
            fail("dynamic_reader(%d) returned NULL. Should have returned pointer to the allocated array",
                    size);
        }

        for (i = 0; i < size; i++) {
            if (res[i] != s_arr[i]) {
                free(res);
                fail("Wrong array member with input \"%s\". You had %d as %dth item, expected %d\n",
                        inp, res[i], i + 1, s_arr[i]);
            }
        }
        free(res);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("DynamicRead");
	tmc_register_test(s, test_dyn_reader, "dynamicread");
	return tmc_run_tests(argc, argv, s);
}
