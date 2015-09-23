#include <ctype.h>
#include <string.h>
#include "source.h"
#include <stdio.h>

void reversed_words(char *p)
{
    while(*p != '\0'){
        
        char *alku = p;
        char *loppu = etsiSananLoppu(p);
        p = loppu+1;

        //printf("alku: %p\n", alku);
        //printf("loppu: %p\n", loppu);

        while(alku<loppu){
            swap(alku, loppu);
            alku++;
            loppu--;
        }

        while(!isalpha(*p) && *p != '\0'){ // skipataan niin kauan kuin on välejä tai välimerkkejä tms
            p++;
        }
        
    }
}


char* etsiSananLoppu(char *p){
    while(isalpha(*p)){
        //printf("etsitään sanan loppua indeksistä %p\n", p);
        p++;
    }
    return --p;
}

void swap(char *p1, char *p2){
    char sailo = *p1;
    *p1 = *p2;
    *p2 = sailo;
}
