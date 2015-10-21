#include <stdio.h>
#include "source.h"

/* Objective: Test that your development environment works and you can send tasks to the tmc-server.
 * Make sure that this task prints "Hello World!" and submit task to the server.*/


int main() {
    float arvo = testi();
    printf("%f\n", arvo);
    return 0;
}

float testi(){
    return 1.5;
}
