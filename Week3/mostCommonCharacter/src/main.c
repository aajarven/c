#include <stdio.h>
#include "source.h"

/* This task is from Aalto C Programming Basics course
 * Objective: files
 * Implement function int most_common_character(char* file), that returns the most common alphabetic character in the file.
 * Function should ignore non-alphabetic characters and track only alphabetic characters in the basic ASCII character set: 
 * these characters have character codes of 127 or less.
 * If two characters happen to occur equal number of times, please return the character that is earlier in the alphabetic order.
 * If there is an error, function should return -1. */

int main() {
    char* filename = "textfile.txt";
    char c = most_common_character(filename);
    printf("Most common: '%c' (%d)\n", c, c);
    return 0;
}
