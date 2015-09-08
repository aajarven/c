#include <stdio.h>
#include "source.h"

/* Task is from Aalto C Programming Basics course.
 * Objective: pointer arithmetics
 * Implement function int array_sum(int* array, int size) that gets a pointer to the beginning of an array of integers 
 * and the size of the array as parameters. 
 * Function should calculate and return the sum of the integers in the array. */

int main(void) {
    int array[] = {1, 10, 100, 1000};
    int sum = array_sum(array, 4);
    printf("%d\n", sum);
    return 0;
}
