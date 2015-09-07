#include <stdio.h>
#include "source.h"

void printBox(int width, int height) {

    for(int rivi=0; rivi<height; rivi++){
        for(int sarake=0; sarake<width; sarake++){
            printf("#");
        }
        printf("\n");
    }
}
