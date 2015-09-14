#include "source.h"

int array_sum(int* array, int size){
    int summa=0;

    for(int i=0; i<size; i++){
        summa+=*(array+i);
    }

    return summa;
}
