#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"

int a;
const char** b;


int tiinaRead (char *str, int len, FILE * file)
{
 int i= 0;
 char merkki=0;

 while (i<(len-1)) {
    merkki=fgetc(file);
    if (merkki == EOF) {
      *str = '\0';
      return i;
    } else {
      *str++=merkki;
      i++;
    }
   }
*str = '\0';
return i;
}



START_TEST(test_print) {
    FILE* fp;
    fp = freopen("mockoutput", "w", stdout);
    print(a, b);
    fclose(fp);
    fp = fopen("mockoutput", "r");
    char userString[100];
    char message[100] = "";
    char* rightString = "./test\ncommand\nline\narguments\n";
    tiinaRead(userString, 100, fp);
    int ret = mycompare(userString, rightString, message);
    ck_assert_msg(!ret, "Your output:\n%s\nRight output:\n%s\n%s\n", userString, rightString, message);
    fclose(fp);
}
END_TEST

int main(int argc, const char *argv[])
{
    a = argc;
    b = argv;
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_print, "1");
	return tmc_run_tests(argc, argv, s);
}
