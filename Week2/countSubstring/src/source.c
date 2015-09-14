#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

int count_substring(const char *str, const char *substr){
    int maara = 0;
    char *tutkittavanAlku = (char*) str;
    char* loytyi;

    while(1){
        loytyi = strstr(tutkittavanAlku, substr);
        if (loytyi != NULL){
            maara++;
            tutkittavanAlku=++loytyi;
        } else {
            return maara;
         }
    }

}
