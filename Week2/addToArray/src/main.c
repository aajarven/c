#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/* Task is from Aalto C Programming Basics course.
 * Objective: reallocating memory
 * Implement function int* add_to_array(int *array, int size, int newInt) that adds an integer 'newInt' to the given array 'array'.
 * The length of the array before addition is 'size'.
 * Function returns a pointer to the array. You should be able to call the function several times. */

int main(void) {
    int size = 5;
    int* array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        array[i] = i;
    }
    array = add_to_array(array, size, 10);
    array = add_to_array(array, size+1, 20);
    array = add_to_array(array, size+1, 30);
    for (int i = 0; i < size + 2; i++){
        printf("%d\n", array[i]);
    }
    free(array);
    return 0;
}
