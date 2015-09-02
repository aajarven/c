#include <stdio.h>
#include <math.h>
#include "source.h"

void separate_digits(int number){
    
    //BEGIN SOLUTION
    int count = 0;
    int temp = number;
    while (temp > 0){
        count++;
        temp /= 10;
    }
    int i;
    
    for (i = pow(10, (count-1)); i > 0; i /= 10){
        printf("%d ", (number/i) % 10);
    }
    
    printf("\n");
    
    //END SOLUTION
}
