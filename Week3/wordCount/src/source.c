#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

#define TRUE 1
#define FALSE 0

int word_count(char *filename) {
    FILE *luettava;
    int sanat = 0;
    char luettu;
    int sisAlpha = FALSE;

    if((luettava = fopen(filename, "r")) == NULL){
        return -1;
    }

    do{ // luetaan pois mahdolliset spacet tiedoston alusta
        if((luettu = fgetc(luettava)) == EOF){
            return sanat;
        }
    } while (isspace(luettu));
    ungetc(luettu, luettava);

    do{ // käydään läpi kaikki kirjaimet

        do{ // luetaan niin kauan kun ei spacea
            if((luettu = fgetc(luettava)) == EOF){ 
                if(sisAlpha){ // jos sana loppuu tiedoston loppumiseen, lisätään sekin
                    sanat++;
                }
                return sanat;
            }
            if(isalpha(luettu)){ // merkitään muistiin jos spacella eroteltu osuus sisälsi kirjaimen
                sisAlpha=TRUE;
            }
        } while (!isspace(luettu));
        
        if(sisAlpha){ // jos spacella erotettu osuus sisälsi kirjaimen, lisätään sana
            sanat++;
        }
        sisAlpha = FALSE;

        do{ // luetaan whitespacet pois sanojen välistä
            if((luettu = fgetc(luettava)) == EOF){
                return sanat;
            }
        } while (isspace(luettu));
        ungetc(luettu, luettava);
    } while(luettu != EOF);

    return sanat;
}
