#include <stdlib.h>
#include <string.h>
#include "products.h"


/* initializes the argument list */
void init_list (struct product_list *list)
{
    list->head = NULL;
}

/* Initialize product structure */                                                               
/* Parameters:
 * pr: Pointer to single product structure
 * title, code, stock, price: values to be copied as structure content.
 * Note: code should be truncated to 7 characters, if it is longer
 */
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
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    struct product *lisattava = malloc(sizeof(struct product));
    init_product(lisattava, title, code, stock, price, NULL);

    struct product *eka = start->head;
    if(eka == NULL){
        start->head = lisattava;
    } else {
        struct product *mahdollinenViimeinen = start->head;
        while (mahdollinenViimeinen->next != NULL){
            mahdollinenViimeinen=mahdollinenViimeinen->next;
        }
        mahdollinenViimeinen->next = lisattava;
    }
    return lisattava;

}

/* Find product */
/* Parameters:
 * start: The head node
 * code: product code to be found
 * 
 * Returns: Pointer to the first instance of product, or NULL if not found
 */
struct product *find_product(struct product_list *start, const char *code) {
    struct product *tutkittava = start->head;
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
 * start: The head node
 * code: value to be removed
 *
 * Enough to remove first istance, no need to check for dublicates
 *
 * Returns: The number of removed items (0 or 1)
 */
int remove_product(struct product_list *start, const char *code) {
    struct product *tutkittava = start->head;
    struct product *edellinen = NULL;
    while (tutkittava != NULL){
        if (strncmp(tutkittava->code, code, 7) == 0){
            break;
        }
        edellinen = tutkittava;
        tutkittava = tutkittava->next;
    }
    if(tutkittava == NULL){
        return 0;
    }
    free(tutkittava->title);
    if(edellinen == NULL){
        start->head = tutkittava->next;
    } else {
        edellinen->next = tutkittava->next;
    }
    free(tutkittava);                                                                        

    return 1;

}

/* Delete list */
/* Parameters:
 * start: list head
 *
 * Returns: 1, when list has been deleted
 */
int delete_list(struct product_list *listhead) {
    struct product *poistettava = listhead->head;
    struct product *seuraava;
    while(poistettava != NULL){
        seuraava = poistettava->next;
        free(poistettava->title);
        free(poistettava);
        poistettava = seuraava;
    }
    return 1;
    listhead->head = NULL;
}
