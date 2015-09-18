#include <stdio.h>
#include "source.h"

/* This task is from Aalto C Programming Basics course
 * Objective: files
 * Implement function int line_count(char* file), that calculates the number of lines in the given file and returns it.
 * If there is an error, function should return -1. If the file is empty, function should return 0.
 * If the last line of the file is not empty, it should be counted as a line, even if it doesn't end in a newline character. */

int main() {
    char* filename = "textfile.txt";
    int ret = line_count(filename);
    printf("%d\n", ret);
    return 0;
}
