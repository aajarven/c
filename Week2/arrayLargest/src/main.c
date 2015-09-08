#include <stdio.h>
#include "source.h"

/* Task is from Aalto C Programming Basics course.
 * Objective: arrays and pointers
 * Implement function int largest_number(int* array) that gets a pointer to array of integers. 
 * The pointer points to first number of an array and the last number is -1 but the length is unknown.
 * All the other values of the array are positive. Function should return the largest number in the array. */

int main(void) {
    int array[] = {2, 8, 5, 3, 1, 9, 2, -1};
    int largest = largest_number(array);
    printf("%d\n", largest);
    return 0;
}
