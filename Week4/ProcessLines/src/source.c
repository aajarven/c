#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"
#include <errno.h>
#include <limits.h>

#define RIVINPITUUS 100

int read_lines(char *filename, char ***array, int size) {
    FILE *luettava;
    if ( ! (luettava = fopen(filename, "r")) ){
        fprintf(stderr, "%s\n", strerror(errno));
    }

    // lasketaan rivien määrä tiedostossa
    int rivimaara = 0;
    char luettu;
    while((luettu = fgetc(luettava)) != EOF){
        if (luettu = '\n'){
            rivimaara++;
        }
    }
    rewind(luettava);

    if(size < rivimaara){
        *array = malloc((rivimaara+1)*sizeof(char *));
    }
    
    int rivinro = 0;
    int kirjainRivilla = 0;
    char *rivi = malloc(RIVINPITUUS*sizeof(char));
    while(fscanf(luettava, "%c", &luettu) != EOF){
        rivinpituus++;
        if (luettu == '\n'){
            rivi[kirjainRivilla] = '\0'
    
}


int shortest_string (char **array, int len)
{

    fprintf(stderr, "shortest\n");
    int lyhyimmanPituus = INT_MAX;
    int lyhyimmanIndeksi = -1;
    int tutkittava = 0;

    while(tutkittava < len){
        int tutkittavanPituus = strlen(array[tutkittava]);
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
