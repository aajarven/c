#include <ctype.h>
#include <stdio.h>
#include "source.h"

int count_alpha(const char *str) {
    int kirjaimet = 0;
    while(*str != '\0'){
        if(isalpha(*str)){
            kirjaimet++;
        }
        str++;
    }
    return kirjaimet;
}

