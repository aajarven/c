#include <stdio.h>
#include "source.h"

/* This task is from Aalto C Programming Basics course
 * Objective: files and char pointer arrays
 * 
 * Read lines from file to string array and print a) the shortest of them, 
 * and b) the first in alphabetical order.
 * Do not make any assumptions about the line length or the number of lines in the file.
 *
 * Function  int read_lines(char *filename, char ** array, int size) read the lines 
 * from file filename and returns the pointer to the array holding the lines. 
 * The initial size of the array is given in argument size and pointer to this 
 * initial array in argument array. Function needs to (re)allocate more space to the 
 * array. The argument array can be NULL and the size 0, in which case no space has 
 * been allocated in advance. Function returns a pointer to the array where the last 
 * element in the array is indicated with NULL. All elements preceding it are pointers 
 * to strings. Each string contains one line of the file.
 * Return -1, if the file open failed. This is needed to distinguish this from empty file.
 *
 * Function int shortest_line(char **​array, int len) prints the shortest line, but 
 * also return the position of the line in the array. If the array is empty, 
 * function can return -1.
 * For identical lenghts, return the earlier position.
 *
 * Function int find_lexi_first (char **array, int len) locates the lexicographically
 * first line and returns its position in the array. For an empty array funtion returns -1.
 * For similar lines, return the earlier position.
 */

int main() {
    char* filename = "../test/rfc791.txt";
    char **array;//=NULL;
    int size = 0;

    int len = read_lines(filename, &array, size);
    printf("Read %d lines from file %s\n", len, filename);

    int  index = shortest_string (array, len);
    printf("Shortest line in row %d is: %s\n", index+1, array[index]);

    index = find_lexi_first (array, len);
    printf("Lexicographically first row in pos %d is: %s\n", index+1, array[index]);

    return 0;
}
