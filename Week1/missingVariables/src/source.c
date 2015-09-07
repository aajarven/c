#include <stdio.h>
#include "source.h"

void print_sums(void){
    int a = 5;
    int b = 6;
    double c = 2.3;
    double d = 4.1;

    int sum1 = a+b;
    double sum2 = c+d;

    printf("%d + %d = %d\n", a, b, sum1); //a + b = sum1
    printf("%.1f + %.1f = %.1f\n", c, d, sum2); //c + d = sum2
}
