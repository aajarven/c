#include <ctype.h>
#include <string.h>
#include "source.h"

void turn_around(char *p){
    char *loppu = etsiLoppu(p)-1;    
    char *alku = p;

    while(alku<loppu){
        swap(alku, loppu);
        alku++;
        loppu--;
    }

    (void) p;
}

char* etsiLoppu(char *p){
    char *tutkittava = (char*) p;
    while(*tutkittava != '\0'){
        tutkittava++;
    }
    return tutkittava--;
}

void swap(char *p1, char *p2){
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
