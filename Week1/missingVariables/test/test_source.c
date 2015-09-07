#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "../src/source.h"


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


START_TEST(test_hello) {
    FILE* fp;
    fp = freopen("mockoutput", "w", stdout);
    print_sums();
    fputc(EOF,fp);
    fclose(fp);
    fp = fopen("mockoutput", "r");
    char userString[100];
    for (int i=0; i<100;i++) userString[i] = '\0';
    char message[100] = "";
    char* rightString = "5 + 6 = 11\n2.3 + 4.1 = 6.4\n";
    int len = tiinaRead(userString, 100, fp);
     if (len==0) fail ("No output produced\n");
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
