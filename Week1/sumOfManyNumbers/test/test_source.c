#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"

START_TEST(test_count_sum)
{
    FILE *mock_input = freopen("mockinput", "w+", stdin);
     fputs("6 8 10 0", mock_input);
     fseek(mock_input, 0, SEEK_SET);
     freopen("mockoutput", "w", stdout);
     sum_of_many_numbers();
     fflush(stdout);
     FILE *fp = fopen("mockoutput", "r");
     char str [100];
     memset(str, 0, sizeof(str));
     fgets(str, 100, fp);
     char *ref = "24\n";
     char infostr[100] = "";
     int ret = mycompare(str, ref, infostr);
     fail_unless(!ret, "When giving input \"6 8 10 0\", your output:\n%s\nReference output:\n%s\nReason: %s\n",
            str, ref, infostr);
     fclose(fp);
     
     mock_input = freopen("mockinput", "w+", stdin);
     fputs("-6 7 4 a", mock_input);
     fseek(mock_input, 0, SEEK_SET);
     freopen("mockoutput", "w", stdout);
     sum_of_many_numbers();
     fflush(stdout);
     fp = fopen("mockoutput", "r");
     memset(str, 0, sizeof(str));
     fgets(str, 100, fp);
     ref = "5\n";
     ret = mycompare(str, ref, infostr);
     fail_unless(!ret, "When giving input \"-6 7 4 a\", your output:\n%s\nReference output:\n%s\nReason: %s\n",
            str, ref, infostr);
     fclose(fp);
}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("sumOfmany");

	tmc_register_test(s, test_count_sum, "sumOfMany");
        
	return tmc_run_tests(argc, argv, s);
}
