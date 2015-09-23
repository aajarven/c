#include "findstr.h"
#include <string.h>
#include <stdio.h>

/* Searches for given string inside a file, starting from given offset.
 * (fix to original solution provided by Markus Holmström)
 * 
 * Parameters:
 * str: The string to be looked for
 * filename: name of the file to be searched
 * offset: starting point for the search, in bytes
 * 
 * Parameter:
 * The offset from which the string was first found */
long find_string(const char *str, const char *filename, long offset)
{
    //(void) str;
    //(void) filename;
    //(void) offset;
    
    FILE *luettava = fopen(filename, "r");
    int tasmaaAsti = 0;
    char *tasmaaAlku = 0;
    char *tutkittava = (char*) offset;
    char luettu;
    //char *etsittavanAlku = str;

    if (luettava == NULL){
        return -1;
    }

    if (fseek(luettava, offset, SEEK_SET) == -1){
        return -1;
    }

    while ((luettu=fgetc(luettava)) != EOF){
        if(luettu == str[tasmaaAsti]){
            if(tasmaaAsti == 0){
                tasmaaAlku = tutkittava;
            }
            tasmaaAsti++;
            if(str[tasmaaAsti]=='\0'){
                return (long) tasmaaAlku;
            }
        } else {
            tasmaaAsti = 0;
        }
        
        if(str[tasmaaAsti]=='\0'){
            return (long) tasmaaAlku;
        }

        tutkittava++;
    }
    
    return -1;
}

