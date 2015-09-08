#include <stdio.h>
#include "source.h"

/* Task is from Aalto C Programming Basics course.
 * Objective: pointers
 * Implement function void swap(int* a, int* b) that gets two pointers to integers as parameters. 
 * The function should swap the content of pointed integers. */

int main(void) {
    int a = 1;
    int b = 2;
    printf("Before swap a = %d and b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap a = %d and b = %d\n", a, b);
    return 0;
}
