#include <stdio.h>
#include "source.h"

/*Task is from Aalto C Programming Basics course.
 * Objective: string
 * Write a function int count_alpha(const char* str) that count the number of alphabetic character in given string str 
 * and returns the count. */

int main(void) {
    char *str = "This is a string";
    printf("%d\n", count_alpha(str));
    return 0;
}
