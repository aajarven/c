#include <stdio.h>
#include "source.h"

/* Task is from Aalto C Programming Basics course.
 * Objective: arrays and scanf
 * Implement function int array_reader(int* array, int maxSize) that reads integer values using scanf into array. 
 * Parameter maxSize tells the maximun length of the array and the maximum number of value to be read.
 * If user doesn't give a valid integer value, the array ends, even if the array wasn't full yet.
 * The function returns the final size of the array at the end which can be smaller than maxSize,
 * if the user entered a non-valid integer. */

int main(void) {
    int array[10];
    int size = array_reader(array, 10);
    printf("%d\n", size);
    return 0;
}
