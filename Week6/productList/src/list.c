#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"


/* Initialize product structure */
/* Parameters:
 *  * pr: Pointer to single product structure
 *   * title, code, stock, price: values to be copied as structure content.
 *    * Note: code should be truncated to 7 characters, if it is longer
 *     */
void init_product(struct product *pr, const char *title, const char *code,
        int stock, double price, struct product *next)
{
    pr->title =  malloc((strlen(title)+1)*sizeof(char));
    strcpy(pr->title, title);
    strncpy(pr->code, code, 8); 
    pr->code[7] = '\0';
    pr->stock = stock;
    pr->price = price;
    pr->next = next;
}


/* Add product */
/* Parameters:
 * start: start of the linked list
 * title, code, stock, price: to be copied as created structure content
 * 
 * Returns: pointer to the newly added node in the linked list
 */
struct product *add_product(struct product *start, const char *title, const char *code,
        int stock, double price) {
    struct product *lisattava = malloc(sizeof(struct product));
    init_product(lisattava, title, code, stock, price, NULL);
    if(start == NULL) {
        return lisattava;
    }

    struct product *mahdollinenViimeinen = start;
    while (mahdollinenViimeinen->next != NULL){
        mahdollinenViimeinen=mahdollinenViimeinen->next;
    }

    mahdollinenViimeinen->next = lisattava;
    return lisattava;
}

/* Find product */
/* Parameters:
 * start: first element in the linked list
 * code: product code to be found
 * 
 * Returns: Pointer to the first instance of product, or NULL if not found
 */
struct product *find_product(struct product *start, const char *code) {
    struct product *tutkittava = start;
    while (tutkittava != NULL){
        if (strncmp(tutkittava->code, code, 7) == 0){
            return tutkittava;
        }
        tutkittava = tutkittava->next;
    }
    return NULL;
}

/* Remove Product */
/* Parameters:
 * start: The first element in list
 * code: value to be removed
 * 
 * Returns: Pointer to the first element in the linked list
 */
struct product *remove_product(struct product *start, const char *code) {
    if (strncmp(start->code, code, 7) == 0){
        struct product *palautettava = start->next;
        free(start->title);
        free(start);
        return palautettava;
    } else {
        struct product *tutkittava = start->next;
        struct product *edellinen = start;
        while (tutkittava != NULL){
            if (strncmp(tutkittava->code, code, 7) == 0){
                printf("löytyi etsitty, jonka code on %s\n", code);
                break;
            }
            edellinen = tutkittava;
            tutkittava = tutkittava->next;
        }
        if(tutkittava == NULL){
            return start;
        }
        free(tutkittava->title);
        edellinen->next = tutkittava->next;
        free(tutkittava);
        return start;
    }
}

/* Delete list */
/* Parameters:
 * start: first element in linked list
 * 
 * Returns: 1, when list has been deleted
 */
int delete_list(struct product *start) {
    struct product *poistettava = start;
    struct product *seuraava;
    while(poistettava != NULL){
        seuraava = poistettava->next;
        free(poistettava->title);
        free(poistettava);
        poistettava = seuraava;
    }
    return 1;
}
