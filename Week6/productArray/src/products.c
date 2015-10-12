#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "products.h"


/* Initialize product structure */
/* Parameters:
 * pr: Pointer to single product structure
 * title, code, stock, price: values to be copied as structure content.
 * Note: code should be truncated to 7 characters, if it is longer
 */
void init_product(struct product *pr, const char *title, const char *code,
        int stock, double price)
{
    pr->title = malloc((strlen(title)+1)*sizeof(char));
    strcpy(pr->title, title);
    strncpy(pr->code, code, 7);
    pr->stock = stock;
    pr->price = price;
}

/* Add product to array */
/* Parameters:
 * pa: Product array to where a new item is added
 * title, code, stock, price: values to be copied as structure content.
 * Note: code should be truncated to 7 characters, if it is longer
 */
void add_product(struct product_array *pa, const char *title, const char *code,
        int stock, double price)
{

    if (pa->arr == NULL){
       pa->arr = malloc(sizeof(struct product));
       pa->count = 0;
    }
    
    pa->arr = realloc(pa->arr, pa->count+1);   

    init_product(&pa->arr[pa->count], title, code, stock, price);
    pa->count++;
}

/* Remove all array elements */
/* Parameters:
 * pa: Product array to be removed
 *
 * Returns: 1 when the function is properly implemented
 */
int remove_all(struct product_array *pa)
{
    pa->arr = NULL;
    pa->count = 0;
    free(pa);
    return 1;
}


/* Find product */
/* Parameters:
 * pa: Product array structure
 * code: product code that will be searched for
 *
 * Returns: pointer to the matching product in array, NULL if not found
 */
struct product *find_product(struct product_array *pa, const char *code) {
    struct product *tutkittava = malloc(sizeof(struct product));
    for (unsigned int i = 0; i < pa->count; i++){
        tutkittava = &(pa->arr)[i];
        if (strncmp(tutkittava->code, code, 7)){
            return tutkittava;
        }
    }
    free(tutkittava);
    return NULL;
}


/* Delete product */
/* Parameters:
 * pa: Product array structure
 * code: product code that will be deleted
 */
void delete_product(struct product_array *pa, const char *code) {
    struct product *poistettava = find_product(pa, code);

    unsigned int alkuIndeksi = (poistettava - pa->arr) / sizeof(struct product);
    for (unsigned int i=alkuIndeksi; i < pa->count-1; i++){
        pa->arr[i] = pa->arr[i+1];
    }
    pa->count--;
    pa->arr = realloc(pa->arr, pa->count);
}
