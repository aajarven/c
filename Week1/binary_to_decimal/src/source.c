#include "source.h"
#include "math.h"

int binary_to_decimal(int binary) {
    int potenssi=0;
    int desimaaliluku=0;

    while(binary>0){
        if (binary%10!=0){
            desimaaliluku += pow(2,potenssi);
        }
        potenssi++;
        binary/=10;
    }

    return desimaaliluku;
}
