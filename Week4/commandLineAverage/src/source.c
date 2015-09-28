#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source.h"
#include <unistd.h>

int * arg2int(int argc, const char* argv[]) {
    
    int *argumentit = malloc((argc-1)*sizeof(int));
    int i = 1;

    while(i<argc){
        argumentit[i-1]= atoi(argv[i]);
        i++;
    }

    return argumentit;

}

float arrayAvg(int size, int *array) {
    int summa = 0;
    int i = 0;

    while(i<size){
        summa=summa+array[i];
        i++;
    }

    return summa/size;
}



