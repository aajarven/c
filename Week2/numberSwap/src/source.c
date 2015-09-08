#include <stdio.h>
#include "source.h"

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
