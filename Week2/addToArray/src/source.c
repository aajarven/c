#include "source.h"
#include <stdio.h>
#include <stdlib.h>

int *add_to_array(int *array, int size, int newInt) {
    array = realloc(array, (size+1)*sizeof(int));
    *(array+size) = newInt;
    return array;  // replace this
}

