#include <stdio.h>
#include "source.h"

/*Task is from Aalto C Programming Basics course.
 * Objective: string
 * Write a function void reversed_words(char* p) that reverses every word in the given string, but not the full string.
 * Word consist alphanumeric characters and any non-alphanumeric character ends the current word. 
 * Non-alphanumeric character are not reversed. For exaple "Example string" should become "elpmaxE gnirts" */

int main(void) {
    
    char testString[] = "A palindrome is a word,\n"
        "phrase, number, or other sequence of\n"
        "symbols or elements, whose meaning\n"
        "may be interpreted the same way in\n"
        "either forward or reverse direction\n";
    printf("1: %s", testString);
    reversed_words(testString);  
    printf("2: %s\n", testString);
    return 0;
}
