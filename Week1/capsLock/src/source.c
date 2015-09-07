#include <stdio.h>
#include <ctype.h>
#include "source.h"

void print_capsLock(){
    char luettu;

    for(int i=0; i<10; i++){
        scanf("%c", &luettu);
        if(isalpha(luettu)){
            printf("%c", toupper(luettu));
        } else {
            printf("%c", luettu);
        }
    }
    printf("\n");
}
