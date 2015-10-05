#include <stdio.h>
#include "tools.h"

/*Implement SWAP(t, x, y) macro in tools.h. Swap should interchange arguments x and y of type t.*/

int main(void) {
#ifdef SWAP
    int number1 = 1;
    int number2 = 2;
    char character1 = 'a';
    char character2 = 'b';
    
    printf("Before swap: %d %d\n", number1, number2);
    SWAP(int, number1, number2);
    printf("After swap: %d %d\n", number1, number2);
    printf("Before swap: %c %c\n", character1, character2);
    SWAP(char, character1, character2);
    printf("After swap: %c %c\n", character1, character2);
#else
    printf("Implement SWAP first\n");
#endif

    return 0;
}
