#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

int most_common_character(char *filename) {
    char alku = 'A';
    char loppu = 'z';
    int* kirjainmaarat = malloc((loppu-alku)*sizeof(int));
    FILE *luettava = fopen(filename, "r");
    char luettu;

    if(luettava == NULL){
        return -1;
    }

    for(int nollattava = 0; nollattava < loppu-alku; nollattava++){
        kirjainmaarat[nollattava] = 0;
    }

    while((luettu = fgetc(luettava)) != EOF){
        if(luettu >= alku && luettu <= loppu){
            kirjainmaarat[luettu-alku]++;
        }
    }

    int suurinMaara = 0;
    char yleisinKirjain = 0;
    for(int i = 0; i<loppu-alku; i++){
        if(kirjainmaarat[i]>suurinMaara){
            suurinMaara = kirjainmaarat[i];
            yleisinKirjain = alku+i;
        }
    }
    return yleisinKirjain;
}
