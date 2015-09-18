#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


void printChar(char *buffer, int c)
{
    if (c == -1)
        sprintf(buffer, "EOF (-1)");
    else if (c < 32)
        sprintf(buffer, "%d", c);
    else if (c < 128)
        sprintf(buffer, "'%c' (%d)", c, c);
    else
	    sprintf(buffer, "%d", c);
}

START_TEST(test_most_common) {
    char *files[] = {"nonexistent.txt", "empty.txt", "oneline.txt", "lines.txt", "rfc791.txt"};
    int results[] = {-1, 0, 'e', 'f', 'e'};
    int i;
    int ret;
    
    char buf[16];
    char buf2[16];
    for (i = 0; i < 5; i++) {
        ret = most_common_character(files[i]);
        printChar(buf, results[i]);
        printChar(buf2, ret);
        fail_unless(ret == results[i],
                "Should have returned %s for file %s. You returned %s.",
                buf, files[i], buf2);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("MostCommonChar");
	tmc_register_test(s, test_most_common, "mostcommonchar");
	return tmc_run_tests(argc, argv, s);
}
