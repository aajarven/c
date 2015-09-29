#include "source.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int encode_string(char* source, char* dest, int col_count, char pad)
{
    char **matriisi = create_encode_matrix(source, col_count, pad);
    printf("encode saatu\n"); 
    int rivit = tarvittavatrivit(strlen(source), col_count);
    int i=0;
    for(int sarake = 0; sarake < col_count; sarake++){
        for(int rivi = 0; rivi < rivit; rivi ++){
            printf("i: %i, sijoitettava: %c\n", i, matriisi[sarake][rivi]);
            dest[i] = matriisi[sarake][rivi];
            i++;
        }
    }
    
    return i;
}


int decode_string(char* source, char* dest, int col_count)
{
return 0;
}

int encode_string_with_key(char* source, char* dest, char* key, char pad)
{

return 0;
}


int decode_string_with_key(char* source, char* dest, char* key)
{
return 0;
}

char** create_encode_matrix(char *source, int col_count, char pad){
    int rivit = tarvittavatrivit(strlen(source), col_count);
    int koodattavan_pituus = strlen(source);
    
    char **palautus = malloc(col_count * sizeof(char*));
    for(int i=0; i<col_count; i++){
        palautus[i]=malloc(rivit * sizeof(char));
    }
//    printf("sarakkeet: %i, rivit: %i\n", col_count, rivit);
    char laitettava;

    for(int rivi = 0; rivi < rivit ; rivi++){
        for(int sarake = 0; sarake < col_count; sarake++){
            int luettava = rivi*col_count + sarake;
            
            if (luettava >= koodattavan_pituus){
                laitettava = pad;
            } else {
                laitettava = source[luettava];
            }
            
//            printf("laitettava: %c, rivi: %i, sarake: %i\n", laitettava, rivi, sarake);
            palautus[sarake][rivi] = laitettava;
        }
    }
    return palautus;
}

int tarvittavatrivit(int lukuja, int sarakemaara){
    if(lukuja%sarakemaara == 0){
        return lukuja/sarakemaara;
    } else {
        return lukuja/sarakemaara + 1;
    }
} 
