#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/* Write function saveSum(int* ap, int* bp, int* cp) that counts the sum of the integers pointed by ap and bp 
 * and saves the sum into the memory pointed by cp.*/

int main() {
    int a = 5;
    int* ap = &a;
    int b = 4;
    int* bp = &b;
    int c = 0;
    int* cp = &c;
    saveSum(ap, bp, cp);
    printf("%d\n", c);
    return 0;
}
