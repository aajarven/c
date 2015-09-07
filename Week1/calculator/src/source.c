#include <stdio.h>
#include "source.h"

void calculate(void) {
    float luku1;
    float luku2;
    char operaattori;

    if(!scanf("%f", &luku1)){
        printf("error\n");
        return;
    }

    do{
        scanf("%c", &operaattori);
    } while(operaattori==' ');
    
    // Ruma tapa päästä eroon erottavasta välilyönnistä
    char space;
    scanf("%c", &space);

    if(!scanf("%f", &luku2)){
        printf("error\n");
        return;
    }

    switch(operaattori){
        case '+':
            printf("%.2f %c %.2f = %.2f", luku1, operaattori, luku2, luku1+luku2);
            break;
        case '-':
            printf("%.2f %c %.2f = %.2f", luku1, operaattori, luku2, luku1-luku2);
            break;
        case '*':
            printf("%.2f %c %.2f = %.2f", luku1, operaattori, luku2, luku1*luku2);
            break;
        case '/':
            printf("%.2f %c %.2f = %.2f", luku1, operaattori, luku2, luku1/luku2);
            break;
        default:
            printf("error");
    }
    printf("\n");
}
