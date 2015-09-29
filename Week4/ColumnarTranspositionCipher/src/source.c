#include "source.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

int encode_string(char* source, char* dest, int col_count, char pad)
{
    char **matriisi = create_encode_matrix(source, col_count, pad);
    int rivit = tarvittavatrivit(strlen(source), col_count);
    int i=0;
    for(int sarake = 0; sarake < col_count; sarake++){
        for(int rivi = 0; rivi < rivit; rivi ++){
            //printf("i: %i, sijoitettava: %c\n", i, matriisi[sarake][rivi]);
            dest[i] = matriisi[sarake][rivi];
            i++;
        }
    }
    dest[i]='\0';
    
    return i;
}


int decode_string(char* source, char* dest, int col_count)
{
    char **matriisi = create_decode_matrix(source, col_count);
    int rivit = tarvittavatrivit(strlen(source), col_count);
    int i=0;

    for(int rivi = 0; rivi < rivit; rivi ++){
        for(int sarake = 0; sarake < col_count; sarake++){
            //printf("i: %i, sijoitettava: %c\n", i, matriisi[sarake][rivi]);
            dest[i] = matriisi[sarake][rivi];
            i++;
        }
    }
        
    dest[i] = '\0';
           
    return i;
}

int encode_string_with_key(char* source, char* dest, char* key, char pad)
{
    int* jarjestys = sarakkeiden_jarjestys(key);   
    char **matriisi = create_encode_matrix(source, strlen(key), pad);
    int rivit = tarvittavatrivit(strlen(source), strlen(key));
    int kirjoitettava = 0;
    
    //printf("enkoodauksen aloitus\n");
    for(unsigned int sarake=0; sarake<strlen(key); sarake++){
        int tutkittava_sarake = jarjestys[sarake];
        //printf("%i\n", tutkittava_sarake);
        char* lisattava_sarake = matriisi[tutkittava_sarake];
        
        //printf("haettu matriisista\n");
        for(int i=0; i<rivit; i++){
            //printf("%c", lisattava_sarake[i]);
            dest[kirjoitettava] = lisattava_sarake[i];
            kirjoitettava++;
            //printf("forissa kirjoitettu\n");
        }
    }
    dest[kirjoitettava] = '\0';
    
    return kirjoitettava;
}


int decode_string_with_key(char* source, char* dest, char* key)
{

    int* jarjestys = sarakkeiden_jarjestys(key);   
    char **matriisi = malloc(strlen(key)*sizeof(char *));
    int rivit = tarvittavatrivit(strlen(source), strlen(key));
    for(unsigned int i=0; i<strlen(key); i++){
        matriisi[i] = malloc(rivit*sizeof(char));
    }

    char* kirjoitettava = source;

    for(unsigned int i=0; i<strlen(key); i++){
        int tutkittava_sarake = jarjestys[i];
        kirjoita_matriisiin(&matriisi, tutkittava_sarake, kirjoitettava, rivit);
        //printf("kirjoitettiin matriisiin %s\n", source);
        kirjoitettava += rivit;
    }
    
    int i=0;
    for(int rivi = 0; rivi < rivit; rivi ++){
        for(unsigned int sarake = 0; sarake < strlen(key); sarake++){
            //printf("i: %i, sijoitettava: %c\n", i, matriisi[sarake][rivi]);
            dest[i] = matriisi[sarake][rivi];
            i++;
        }
    }
        
    dest[i] = '\0';
           
    return i;
}

void kirjoita_matriisiin(char ***matriisi, int sarake, char* kirjoitettava, int pituus){
    for(int i=0; i<pituus; i++){
        (*matriisi)[sarake][i] = kirjoitettava[i];
    }   
}

char** create_encode_matrix(char *source, int col_count, char pad){
    int rivit = tarvittavatrivit(strlen(source), col_count);
    int koodattavan_pituus = strlen(source);
    
    char **palautus = malloc(col_count * sizeof(char*));
    for(int i=0; i<col_count; i++){
        palautus[i]=malloc(rivit * sizeof(char));
    }

    char laitettava;

    for(int rivi = 0; rivi < rivit ; rivi++){
        for(int sarake = 0; sarake < col_count; sarake++){
            int luettava = rivi*col_count + sarake;
            
            if (luettava >= koodattavan_pituus){
                laitettava = pad;
            } else {
                laitettava = source[luettava];
            }
            
            palautus[sarake][rivi] = laitettava;
        }
    }

    return palautus;
}

char** create_decode_matrix(char *source, int col_count){
    int rivit = tarvittavatrivit(strlen(source), col_count);
    
    char **palautus = malloc(col_count * sizeof(char*));
    for(int i=0; i<col_count; i++){
        palautus[i]=malloc(rivit * sizeof(char));
    }

    int luettava = 0;

    for(int sarake = 0; sarake < col_count ; sarake++){
        for(int rivi = 0; rivi < rivit; rivi++){
            //int luettava = rivi*col_count + sarake;
            palautus[sarake][rivi] = source[luettava];
            luettava++;
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

int* sarakkeiden_jarjestys(char* key){
    int* palautus = malloc(strlen(key)*sizeof(int));
    char edellinen = -1;
    unsigned int edellisen_indeksi = 0;
    char pienin_loydetty = CHAR_MAX;
    unsigned int pienimman_indeksi = 0;

    for(unsigned int i=0; i<strlen(key); i++){
        palautus[i]='\0';
    }

    for(unsigned int i=0; i<strlen(key); i++){
        for(unsigned int j=0; j < strlen(key); j++){
            if(key[j]==edellinen && j > edellisen_indeksi){
                edellisen_indeksi = j;
                palautus[i]=j;
                edellinen = key[j];
                //printf("%i\n", j);
                break;
            } else if (key[j]<pienin_loydetty && key[j] > edellinen) {
                pienin_loydetty=key[j];
                pienimman_indeksi = j;           
            }
        }
        if(palautus[i]=='\0'){
            palautus[i] = pienimman_indeksi;
            edellinen = pienin_loydetty;
            edellisen_indeksi = pienimman_indeksi;
         //   printf("%i\n", pienimman_indeksi);
        }
        pienin_loydetty = CHAR_MAX;
    }

    return palautus;
}

char* hae_sarake(char **matriisi, int sarake, int pituus){
    char *palautettava = malloc(pituus*sizeof(char));
    for(int i=0; i<pituus; i++){
        palautettava[i] = matriisi[sarake][i];
    }
    return palautettava;
}
