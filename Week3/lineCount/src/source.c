#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

int line_count(char *filename) {
    FILE *luettava;
    int rivit = 0;
    int merkkiaRivilla = 0;
    char luettu;

    if((luettava = fopen(filename, "r")) == NULL){
        return -1;
    }

    while((luettu = fgetc(luettava)) != EOF){
        if(luettu != '\n'){
            merkkiaRivilla++;
        } else {
            rivit++;
            merkkiaRivilla=0;
        }
    }

    if(merkkiaRivilla > 0){
        rivit++;
    }

    return rivit;
}
