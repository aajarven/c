#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/* Task is from Aalto C Programming Basics course.
 * Objective: dynamic memory allocation
 * Implement function int* dynamic_reader(int size) that reads integer values from user into array. 
 * Function allocates the needed memory itself. Parameter size tells the number of integer in the array.
 * You can assume that the user types the right number of valid integers. 
 * Function returns a pointer to the array. */

int main(void) {
    int size = 5;
    int* array = dynamic_reader(size);
    printf("Numbers: \n");
    for (int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
    free(array);
    return 0;
}
