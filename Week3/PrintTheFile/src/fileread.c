#include "fileread.h"
#include <stdio.h>
#include <ctype.h>

/* Prints the given file as text on the screen.
 * Only printable characters are shown. Non-printable characters are printed
 * as '?'. <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int textdump(const char *filename)
{
    FILE *luettava;
    char luettu;
    int maara = 0;

    if((luettava=fopen(filename, "r")) == NULL){
        return -1;
    }

    while( (luettu = fgetc(luettava)) != EOF){
        maara++;
        if(isprint(luettu)){
            printf("%c", luettu);
        } else {
            printf("?");
        }
        
    }
    return maara*sizeof(char);
}

