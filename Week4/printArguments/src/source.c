#include <stdio.h>
#include "source.h"

void print(int argc, const char* argv[]) {

    int tulostettava = 0;
    while(tulostettava < argc){
        printf("%s\n", argv[tulostettava]);
        tulostettava++;
    }

}
