#include "source.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>


int encode_string(char* source, char* dest, int col_count, char pad)
{
    char *** matriisi = NULL;
    matriisi = create_encode_matrix(matriisi, source, col_count, pad);
    
    int rivit = strlen(source)/col_count;
    int i=0;

    for(int sarake = 0; sarake < col_count; sarake++){
        for(int rivi = 0; rivi < rivit; rivi ++){
            dest[i] = *matriisi[sarake][rivi];
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

char*** create_encode_matrix(char ***palautus, char *source, int col_count, char pad){
    int rivit = strlen(source)/col_count;
    palautus = malloc(col_count * sizeof(int*));
    for(int i=0; i<rivit; i++){
        palautus[i]=malloc(rivit * sizeof(int));
    }

    char luettu = source[0];
    char laitettava;

    for(int sarake = 0; sarake < col_count; sarake++){
        for(int rivi = 0; rivi < rivit ; rivi++){ 
            if ( luettu != '\0') {
                laitettava = source[col_count*rivi + sarake];
                luettu = laitettava;
            } else {
                laitettava = pad;
            }
            *palautus[sarake][rivi] = laitettava;
        }
    }

    return palautus;
}

