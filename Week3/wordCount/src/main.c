#include <stdio.h>
#include "source.h"

/* This task is from Aalto C Programming Basics course
 * Objective: files
 * Implement function int word_count(char* file), that calculates the number of words in the given file and returns the word count.
 * In this exercise a word is a substring that contains at least one alphabetic character. 
 * Two words are separated by one or more whitespaces characters.
 * If there is an error, function should return -1. */

int main() {
    char* filename = "textfile.txt";
    printf("Word count: %d\n", word_count(filename));
    return 0;
}
