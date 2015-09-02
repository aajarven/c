#include "source.h"

int reverse_digits(int number){
    
    //BEGIN SOLUTION
    int reversed = 0;
    
    while (number != 0){
        reversed *= 10;
        reversed += number % 10;
        number /= 10;
    }
    
    return reversed;
    
    //END SOLUTION
}
