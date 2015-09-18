#include "source.h"

/* Objective: files
 * Implement function int readAndPrint(char* file), opens given file for reading, 
 * reads an integer, a floating point number and a character from given file and 
 * print all items on the screen separated by a space and followed by a new line.
 * Use two decimals when printing a float number.
 * Items in the file are separated by a space. */

int main() {
    char* filename = "file.txt";
    readAndPrint(filename);
    return 0;
}
