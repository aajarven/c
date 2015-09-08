#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "../src/source.h"


void randPal(char *work)
{
    for (int i = 0; i < 5; i++) {
        char c = rand() % ('z' - 'a') + 'a';
        work[i] = c;
        work[9-i] = c;
    }
    work[10] = 0;
}

START_TEST(test_is_palindrome) {
    char workStr[5][20] = { "testi", "sokos", "soimii", "saippuakauppias", "" };
    int corRes[5] = { 0, 1, 0, 1, 1 };
    randPal(workStr[4]);
    for (int i = 0; i < 5; i++) {
        int res = is_palindrome(workStr[i]);
        if (res != corRes[i]) {
            fail("Should return %d for string '%s'. You returned %d",
                    corRes[i], workStr[i], res);
        }
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Testpalindrome");
	tmc_register_test(s, test_is_palindrome, "ispalindrome");
	return tmc_run_tests(argc, argv, s);
}
