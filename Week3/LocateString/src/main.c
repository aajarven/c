#include <stdio.h>
#include "findstr.h"

/* From Aalto */

/* Implement function long find_string(const char *str, const char *filename, long offset) 
 * that finds string str from within file named filename, starting from offset offset. 
 * If string is found, the function returns the offset (as number of bytes from the 
 * beginning of file) to the start of the searched string. 
 * If the string is not found, or there is an error, the function returns -1. 
 * To look for multiple instances of the same string, the function can therefore 
 * be called multiple times: after first successful call, it can be called again 
 * with the returned offset + 1. 
 * Note that string str may itself contain newline character -- for consideration 
 * in case you decide to use fgets for reading the file.
 */

int main()
{
    long output = find_string("kaksi", "testi.txt", 0);
    printf("find: %ld\n", output);
    
    output = find_string("kaksi", "testi.txt", output-1);
    printf("find B: %ld\n", output);
}
