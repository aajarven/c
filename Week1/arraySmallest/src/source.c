#include "source.h"
#include <limits.h>
#include <stdio.h>

int smallest_number(int array[], int size) {
    int pienin = array[0];
    
    for(int i=1; i<size; i++){
        pienin = pienin > array[i] ? array[i]: pienin;
    }
    
    return pienin;
}
