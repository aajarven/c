#include "source.h"

int reverse_digits(int number){
    int kaanteinen = 0;
    
    while(number>0){
        kaanteinen+=number%10;
        number/=10;
    }

    return kaanteinen;    
}
