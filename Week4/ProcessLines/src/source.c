#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"
#include <errno.h>
#include <limits.h>

#define RIVINPITUUS 100
#define RIVIMAARA 100

int read_lines(char *filename, char ***array, int size) {
    FILE *luettava;
    int rivinro = 0;
    int kirjain_rivilla = 0;
    char luettu;
    char edellinen_luettu = '\0';
    int max_linelength = RIVINPITUUS;
    char *rivi = malloc(max_linelength*sizeof(char));

    if(size == 0){
        size = RIVIMAARA;
        *array = malloc(RIVIMAARA*sizeof(char *));
    }

    if((luettava = fopen(filename, "r")) == NULL){
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }
    
    while(fscanf(luettava, "%c", &luettu) != EOF){
        //printf("luettu kirjain %c\n", luettu);
        if (luettu == '\n'){
            //printf("luettu newline\n");
            if(rivinro == size){
                //printf("ifissä\n");
                size *= 2;
                *array = realloc(*array, size);
            }
            rivi[kirjain_rivilla] = '\0';
            //printf("rivinro = %i\n", rivinro);
            (*array)[rivinro] = rivi;
            rivinro++;
            max_linelength = RIVINPITUUS;
            kirjain_rivilla = 0;
            rivi = malloc(max_linelength*sizeof(char));
        } else {
            rivi[kirjain_rivilla]=luettu;
            kirjain_rivilla++;
            if(kirjain_rivilla==max_linelength){
                max_linelength*=2;
                rivi = realloc(rivi, max_linelength);
            }
        }
        
       // printf(rivi);
        //printf("\n");

        edellinen_luettu = luettu;
    }
    
    fclose(luettava);

    if(edellinen_luettu != '\0' && edellinen_luettu != '\n'){
        rivinro++;
    } 

    /*int tulostettava = 0;
    while(tulostettava < rivinro ){
        printf("%s", (*array)[tulostettava]);
        tulostettava++;
    }*/

    (*array)[rivinro] = NULL;
    fprintf(stderr, "paluu tiedostonluvusta\n");
    return rivinro;
}


int shortest_string (char **array, int len)
{

    int tulostettavaRivi = 0;
    fprintf(stderr, "shortest\n");
    int lyhyimmanPituus = INT_MAX;
    int lyhyimmanIndeksi = -1;
    int tutkittava = 0;

    while(tutkittava < len){
        fprintf(stderr, "tutkittava: %i, len: %i\n", tutkittava, len);
        //int tutkittavanPituus = 0;
        //while(array[tutkittava][tutkittavanPituus] != '\0'){
        //    tutkittavanPituus++;
        //}
        int tutkittavanPituus = strlen(array[tutkittava]);
        fprintf(stderr, "tutkittavanPituus: %i", tutkittavanPituus);
        if(tutkittavanPituus < lyhyimmanPituus){
            lyhyimmanIndeksi = tutkittava;
            lyhyimmanPituus = tutkittavanPituus;
        }
        tutkittava++;
    }
    
    return lyhyimmanIndeksi;

}


int find_lexi_first (char **array, int len)
{
    if (len == 0) {
        return -1;
    }

    int tutkittava = 1;
    int ensimmaisenIndeksi = 0;
    
    while(tutkittava < len){
        if (strcmp(array[tutkittava], array[ensimmaisenIndeksi])<0){
            ensimmaisenIndeksi = tutkittava;
        }
        tutkittava++;
    }

    return ensimmaisenIndeksi;
}
