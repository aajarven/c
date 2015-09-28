#include "source.h"

int locate_string(char **stringArray, int len, char * string)
{
    int i=0;
    while(i<len){
        if(stringEquals(stringArray[i], string)){
            return i;
        }
        i++;
    }

    return -1;
}

int stringEquals(char *eka, char *toka){
    do{
        if (*eka != *toka){
            return 0;
        }
        eka++;
        toka++;
    } while (*eka != '\0' && toka != '\0');
    return 1;
}

