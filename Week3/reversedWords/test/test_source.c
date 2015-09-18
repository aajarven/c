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


START_TEST(test_reversed_words) {
    char *workStr[3];
    for (int i = 0; i < 3; i++) {
      workStr[i] = calloc(1, 200);
    }
    strcpy(workStr[0], "Small string to be reversed");
    strcpy(workStr[1],  "A palindrome is a word,\n"
        "phrase, number, or other sequence of\n"
	   "symbols or elements.\n");

    /*    char workStr[3][200] = { "Small string to be reversed",
        "A palindrome is a word,\n"
        "phrase, number, or other sequence of\n"
        "symbols or elements.\n" }; */
    char origStr[3][200];
    char revStr[3][200] = { "llamS gnirts ot eb desrever",
        "A emordnilap si a drow,\n"
        "esarhp, rebmun, ro rehto ecneuqes fo\n"
        "slobmys ro stnemele.\n" };
    
    int count = 2;
    
    for (int i = 0; i < 3; i++) {
      memcpy(origStr[i], workStr[i], 200);
    }

    for (int i = 0; i < count; i++) {
        reversed_words(workStr[i]);
        if (strlen(workStr[i]) > 199) {
	    for (int i = 0; i < 3; i++) {
	        free(workStr[i]);
	    }
            fail("[Task 6.1.c] Produced string is too long. You might have forgot trailing '\0'");
        }
        if (strcmp(workStr[i], revStr[i])) {
	  char buf[400];
	  sprintf(buf, "[Task 6.1.c] Reversing string '%s' should result '%s'. You produced: '%s'",
		  origStr[i], revStr[i], workStr[i]);
	  for (int i = 0; i < 3; i++) {
	      free(workStr[i]);
	  }
	  fail(buf);
        }
    }
    for (int i = 0; i < 3; i++) {
        free(workStr[i]);
    }
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("reverseWords");
	tmc_register_test(s, test_reversed_words, "reversewords");
	return tmc_run_tests(argc, argv, s);
}
