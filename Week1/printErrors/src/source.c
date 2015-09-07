#include <stdio.h>
#include "source.h"

#define TRUE 1
#define FALSE 0

void count_sum(void) {
    int luku1;
    int luku2;
    int validInput = TRUE;

    if(scanf("%i", &luku1)!=1){
        fprintf(stderr, "error\n");
        validInput = FALSE;
    }
    if (scanf("%i", &luku2) != 1){
        fprintf(stderr, "error\n");
        validInput = FALSE;
    }
    if(validInput){
        printf("%i + %i = %i\n", luku1, luku2, luku1+luku2);
    }
}

