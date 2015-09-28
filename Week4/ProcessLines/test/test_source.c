#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_read_lines)
{
    char *files[] = {"nonexistent.txt", "empty.txt", "oneline.txt", "singleline.txt", "lines.txt", "rfc791.txt", "generated.txt" };
    int results[] = {-1, 0, 1, 1, 7, 2887, -1};
    int i, ret;
    char **array;
    int len= 0;
    for (i = 0; i < 6; i++) {
        ret = read_lines(files[i], &array, len);
        switch (i) {
           case 2: fail_unless(ret == results[i], "Should have returned %d for file %s. You returned %d.\n This file does not have end-of-line character at the end of the last line.", results[i], files[i], ret);
           default: fail_unless(ret == results[i], "Should have returned %d for file %s. You returned %d.", results[i], files[i], ret);
        }
    }
}
END_TEST

START_TEST(test_shortest_line)
{
    char *files[] = {"oneline.txt", "alpha.txt", "lines.txt", "beta.txt", "generated.txt" };
    int results[] = { 0, 2, 0, 3, -1};
    int i, ret;
    char **array;
    int len= 0;
    for (i = 0; i < 4; i++) {
        ret = read_lines(files[i], &array, len);
        int pos = shortest_string(array, ret);
        switch (i) {
//           case 2: fail_unless(ret == results[i], "Should have returned %d for file %s. You returned %d.\n This file does not have end-of-line character at the end of the last line.", results[i], files[i], pos);
           default: fail_unless(pos == results[i], "Should have returned %d for file %s. You returned %d.", results[i], files[i], pos);
        }
    }
}
END_TEST


START_TEST(test_first_lexi_line)
{
    char *files[] = {"oneline.txt", "alpha.txt", "lines.txt", "beta.txt", "generated.txt" };
    int results[] = { 0, 3, 0, 1, -1};
    int i, ret;
    char **array;
    int len= 0;
    for (i = 0; i < 4; i++) {
        ret = read_lines(files[i], &array, len);
        int pos = find_lexi_first(array, ret);
        switch (i) {
//           case 2: fail_unless(ret == results[i], "Should have returned %d for file %s. You returned %d.\n This file does not have end-of-line character at the end of the last line.", results[i], files[i], pos);
           default: fail_unless(pos == results[i], "Should have returned %d for file %s. You returned %d.", results[i], files[i], pos);
        }
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("readLines");
	tmc_register_test(s, test_read_lines, "readLines");
	tmc_register_test(s, test_shortest_line, "shortestLine");
	tmc_register_test(s, test_first_lexi_line, "lexiFirst");
	return tmc_run_tests(argc, argv, s);
}
