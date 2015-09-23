#include <stdlib.h>
#include <stdio.h>
#include "source.h"

void readAndPrint(char* file){
    FILE *luettava;
    int luettuInt;
    float luettuFloat;
    char luettuChar;

    if((luettava = fopen(file, "r")) == NULL){
        fprintf(stderr, "tiedostoa ei voida avata");
        return;
    }

    if(fscanf(luettava, "%i %f %c", &luettuInt, &luettuFloat, &luettuChar) != 3){
        fprintf(stderr, "tiedostosta lukeminen epäonnistui");
    } else {
        printf("%i %.2f %c\n", luettuInt, luettuFloat, luettuChar);
    }
    fclose(luettava);
}
