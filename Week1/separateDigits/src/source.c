#include <stdio.h>
#include <math.h>
#include "source.h"

void separate_digits(int number){

    int pituus = ceil(log10(number));
    int numerot[pituus];
    int i = 0;

    while(number > 0){
        numerot[i]= number%10;
        number/=10;
        i++;
    }

    for(int i=pituus-1; i>=0; i--){
        printf("%i ", numerot[i]);
    }

    printf("\n");  
}
