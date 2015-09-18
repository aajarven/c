#include <stdio.h>
#include <string.h>
#include "fileread.h"

/* From Aalto */

/* Implement function textdump that will read the given file (the file name in filename parameter) 
 * and print its contents to the screen as text characters. 
 * If the read character is printable (as determined by the isprint function call), 
 *    it should be printed as is. 
 * If the character is not printable, '?' should be printed instead. 
 * Function returns the number of bytes read, or -1 if there was an error in opening the file.
 */


int main(void)
{
    if (textdump("main.c") == -1) {
        if (textdump("src/main.c") == -1) {
            fprintf(stderr, "Could not open main.c\n");
        }
    }
}
