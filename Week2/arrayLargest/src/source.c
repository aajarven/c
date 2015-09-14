#include "source.h"
#include <stdio.h>

int largest_number(int* array) {
    int suurin = 0;
    int kasiteltava = 0;
    int *kasiteltavap = array;

    while(kasiteltava != -1){
        if(kasiteltava > suurin){
            suurin = kasiteltava;
        }
        kasiteltava=*kasiteltavap;
        kasiteltavap++;
    }
    return suurin;
}
