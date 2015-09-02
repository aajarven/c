#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"


START_TEST(test_print)
{
    FILE* fp;
    fp = freopen("mockoutput", "w", stdout);
    printTree(10);
    fclose(fp);
    fp = fopen("mockoutput", "r");
    char userString[1000];
    char message[100] = "";
    char* rightString = "         *\n        ***\n       *****\n      *******\n     *********\n    ***********\n   *************\n  ***************\n *****************\n*******************\n        ***\n        ***\n";
    //char* rightString2 = "         *         \n        ***        \n       *****       \n      *******      \n     *********     \n    ***********    \n   *************   \n  ***************  \n ***************** \n*******************\n        ***        \n        ***        \n";
    fread(userString, 999, 1, fp);
    int ret = mycompare(userString, rightString, message);
    //int ret2 = mycompare(userString, rightString2, message);
    ck_assert_msg(!ret, "Your output:\n%s\nRight output:\n%s\n%s\n", userString, rightString, message);
    fclose(fp);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("printTree");
	tmc_register_test(s, test_print, "printTree");
	return tmc_run_tests(argc, argv, s);
}
