#include <string.h>
#include <stdio.h>
#include "source.h"


void remove_substr(char *str, const char *sub){
    int subPituus = pituus((char*) sub);
    char *loydetty;
    int lopunpituus = pituus(str);
    
    while((loydetty = strstr((const char*) str,  sub)) != NULL){
        lopunpituus = pituus(str) - (loydetty - str) - subPituus + 1;
        memmove(loydetty, loydetty+subPituus, lopunpituus*sizeof(char));
    }
}

int pituus(char *string){
    int pituus = 0;
    while(*string != '\0'){
        pituus++;
        string++;
    }
    return pituus;
}
