#include <stdio.h>
#include "source.h"

/*Task is from Aalto C Programming Basics course.
 * Objective: string
 * Write a function int count_substring(const char* str, const char* substr) that counts
 * how many times string 'substr' occurs in given string 'str' and returns the count. */

int main(void) {
    char* str = "cat dog dogcat cat catdog";
    printf("%d\n", count_substring(str, "cat"));
    return 0;
}
