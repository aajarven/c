#include <stdio.h>
#include <string.h>
#include "source.h"

/* Write a program that will calculate and print the average of numbers given on the command line.
 *
 * You may need to correct the main also.
 * Implement in source.c the functions:
 *    Function (int *)arg2int(int argc, char **argv) copies the integer values from the string array argv to integer array. 
 *    Return the address of the newly created integer array to the caller.
 *
 *    Function float arrayAvg(int size, int *array) counts the average of the array. The array size is passed as separate argument. 
 *    Function returns the counted average.
 *
 * Print the average in main.
 */

int main(int argc, char *argv[]) {
    int *luvut = arg2int(argc, (const char **) argv);
    printf("%f", arrayAvg(argc-1, luvut));
}
