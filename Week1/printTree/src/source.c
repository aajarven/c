#include <stdio.h>
#include <math.h>
#include "source.h"

void printTree(int height){
    for(int kerros=1; kerros<=height; kerros++){
        tulostaMerkkia(height-kerros, ' ');
        tulostaMerkkia(kerros*2-1, '*');
        //tulostaMerkkia(height-kerros, ' ');
        printf("\n");
    }
    tulostaJalka(height);
}

void tulostaMerkkia(int maara, char merkki){
    for(int i=0; i<maara; i++){
        printf("%c", merkki);
    }
}

void tulostaJalka(int kuusenKorkeus){
    int tyhjat = kuusenKorkeus-2;
    int jalat = 3;

    for(int i=0; i<2; i++){
        tulostaMerkkia(tyhjat, ' ');
        tulostaMerkkia(jalat, '*');
        //tulostaMerkkia(tyjkat, ' ');
        printf("\n");
    }
}
