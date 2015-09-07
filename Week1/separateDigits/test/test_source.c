#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_digits) {
    FILE* fp;
    fp = freopen("mockoutput", "w", stdout);
    separate_digits(908765);
    fclose(fp);
    fp = fopen("mockoutput", "r");
    char userString[1000];
    char message[100] = "";
    char* rightString = "9 0 8 7 6 5 \n";
    fgets(userString, 1000, fp);
    int ret = mycompare(userString, rightString, message);
    ck_assert_msg(!ret, "Your output:\n%s\nRight output:\n%s\n%s\n", userString, rightString, message);
    fclose(fp);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("separateDigits");
	tmc_register_test(s, test_digits, "separateDigits");
	return tmc_run_tests(argc, argv, s);
}
