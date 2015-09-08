#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "../src/source.h"


void randString(char *work, char *rev, int len)
{
    for (int i = 0; i < len; i++) {
        char c = rand() % ('z' - 'a') + 'a';
        work[i] = c;
        rev[len-1-i] = c;
    }
    work[len] = 0;
    rev[len] = 0;
}

START_TEST(test_turn_around) {
    char workStr[5][20] = { "testi", "sokos", "toimii", "0123456789abcdef", "" };
    char origStr[5][20];
    char revStr[5][20] = { "itset", "sokos", "iimiot", "fedcba9876543210", "" };
    randString(workStr[4], revStr[4], 10);
    memcpy(origStr, workStr, sizeof(origStr));
    for (int i = 0; i < 5; i++) {
        turn_around(workStr[i]);
        if (strlen(workStr[i]) > 19) {
            fail("[Task 6.1.a] Produced string is too long. You might have forgot trailing '\0'");
        }
        if (strcmp(workStr[i], revStr[i])) {
            fail("[Task 6.1.a] Reversing string '%s' should result '%s'. You produced: '%s'",
                    origStr[i], revStr[i], workStr[i]);
        }
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("TurnAround");
	tmc_register_test(s, test_turn_around, "turnaround");
	return tmc_run_tests(argc, argv, s);
}
