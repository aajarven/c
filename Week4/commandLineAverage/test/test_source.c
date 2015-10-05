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

START_TEST(test_args2int) {

    const char *message[8] = {"0","10","20","30","40","50","60","70"};
    int len = 8;
    int *arr=NULL;

    arr = arg2int (len, message);

    fail_if(arr==NULL,"Not yet implemented memory allocation for the integer array or did not return the address correctly\n");
    fail_if((*arr==0),"Remember that the program name is in the position 0 in argv\n");
    for(int i=0; i<len-1;i++) {
//      printf("i: %d, arr[i]:%d\n", i, *(arr+i));
      if (!((i+1)*10==*(arr+i)))
         fail("The elements in the integer array do not match the string array's numbers\n");
      }

}
END_TEST

START_TEST(test_arrayavg) {

   int len = 20;
   int *arr;
   float avg;

   arr = malloc(sizeof(int)*len);
   for(int i=0; i<len; i++)
   {   *(arr+i)= i*5;
   }

   avg = arrayAvg(len,arr);

   if (fabs(avg-47.5)>0.7)  //Return back to 0.5 after this course!!!!
      fail("Counting the average was not correct or function did not return the value properly\n. You returned %.2f, which differs from the correct value 0.5 or more.\n", avg);

/*   if (fabs(avg-47.5)>0.05)
      fail("You returned %.2f, the correct value is of by a small margin (0.05 to 0.5). The difference is so small that the reason for it could be the inaccuracy of float type. Use a more accurate type for the sum.\n", avg);
*/


}
END_TEST


START_TEST(test_avgargs) {

    /*Check that the main function contains argv within the function.
    So at least two appearances in the file must be there
    */

    FILE *fp = fopen("../src/main.c", "r");
    char userString[100];;
    char *tmp;
    int count =0;


    while  (!feof(fp))  {

      fgets(userString, 100, fp);

      tmp = userString;

      while ( (tmp = strstr(tmp, "argv")) )
      {
         count++;
         tmp++;
      }
    }
    fail_if((count<2),"You must use argv and pass it to the functions\n");

}
END_TEST




int main(int argc, const char *argv[])
{
    a = argc;
    b = argv;
    srand((unsigned)time(NULL));
	Suite *s = suite_create("IntegerArguments");
	tmc_register_test(s, test_args2int, "args2int");
	tmc_register_test(s, test_arrayavg, "arrayarg");
	tmc_register_test(s, test_avgargs, "avgargs");


	return tmc_run_tests(argc, argv, s);
}
