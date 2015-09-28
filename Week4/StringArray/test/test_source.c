#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "../src/source.h"


void pr_array(char *buf, int *arr, int n)
{
    char b[40];
    sprintf(buf, "{");
    while (n--) {
        sprintf(b, "%d", *arr++);
        if (n)
            strcat(b, ", ");
        strcat(buf, b);
    }
    strcat(buf, "}");
}


START_TEST(test_locate_string)
{
    char *strarray[] = { "one", "abac", "tammi", "aba" };
    char *searchstring[] = { "two", "one", "tammi", "aba" };
    int  results[] ={-1,0,2,3};
    int location;
    
    for (int i = 0; i < 4; i++) {
        location = locate_string(strarray,4,searchstring[i]);
//        printf("Test %d: returned location %d, correct location %d\n", i, location, results[i]);
        if (location !=results[i]) {
            if ((location <0)&&(results[i] >=0))
               fail("You missed to find an existing element from the array. Check you test and indexing");
            else if ((location >0)&&(results[i] >=0))
               fail("You did not provide a correct location value back. Is the inxex corrext? Did you compare the whole strings?");
            else
               fail("Your function did not work properly.");
        }
    }
}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
    Suite *s = suite_create("StringArray");

    tmc_register_test(s, test_locate_string, "StringArray");
    
    return tmc_run_tests(argc, argv, s);
}
