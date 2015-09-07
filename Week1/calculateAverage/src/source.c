#include <stdio.h>
#include "source.h"

void calculate_average(){
    int lkm = 0;
    int summa = 0;
    float keskiarvo = 0;
    int luettu;

    while(scanf("%i", &luettu) == 1){
        if(luettu == -1) {
            break;
        }
        lkm++;
        summa += luettu;
    }

    if (lkm > 0){
        keskiarvo = (float) summa / lkm;
    }

    printf("%1.2f\n", keskiarvo);
}
