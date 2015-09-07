#include <stdio.h>
#include <stdlib.h>
#include "source.h"

void sum_of_many_numbers(void){
    int summa = 0;
    int luettu;

    while(scanf("%i", &luettu) == 1){
        if(luettu == 0) {
            break;
        }
        summa += luettu;
    }

    printf("%i\n", summa);    
}
