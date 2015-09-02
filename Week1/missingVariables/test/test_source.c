#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_hello) {
    FILE* fp;
    fp = freopen("mockoutput", "w", stdout);
    print_sums();
    fclose(fp);
    fp = fopen("mockoutput", "r");
    char userString[100];
    char message[100] = "";
    char* rightString = "5 + 6 = 11\n2.3 + 4.1 = 6.4\n";
    fread(userString, 99, 1, fp);
    int ret = mycompare(userString, rightString, message);
    ck_assert_msg(!ret, "Your output:\n%s\nRight output:\n%s\n%s\n", userString, rightString, message);
    fclose(fp);
}
END_TEST

int main(int argc, const char *argv[]) {
    srand((unsigned)time(NULL));
	Suite *s = suite_create("missingVariables");
	tmc_register_test(s, test_hello, "missingVariables");
	return tmc_run_tests(argc, argv, s);
}
