#include <ctype.h>
#include <string.h>
#include<stdio.h>
#include "source.h"

char* etsiLoppu(const char *p){
    char *tutkittava = (char*) p;
    while(*tutkittava != '\0'){
        tutkittava++;
    }
    return tutkittava--;
}

int is_palindrome(const char *p){

    char *loppu =  etsiLoppu(p)-1;
    char *alku = (char*) p;

    while(alku<loppu){
        
        if(*alku != *loppu){
            return 0;
        }
        
        alku++;
        loppu--;
    }

    return 1;
}


