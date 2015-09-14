#include "source.h"
#include <stdio.h>
#include <stdlib.h>

int* dynamic_reader(int size) {
    int *luetut = malloc(size * sizeof(int));
    int *kasiteltava = luetut;

   // printf("%p %p",  (void*) luetut, (void*) kasiteltava);

    while(kasiteltava <= &luetut[size-1]){
        scanf("%i", kasiteltava);
        //printf("%p", (void*) kasiteltava);
        kasiteltava++;
    }
    return luetut;
}
