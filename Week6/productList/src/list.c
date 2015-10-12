#include <stdlib.h>
#include "list.h"


/* Add product */
/* Parameters:
 * start: start of the linked list
 * title, code, stock, price: to be copied as created structure content
 * 
 * Returns: pointer to the newly added node in the linked list
 */
struct product *add_product(struct product *start, const char *title, const char *code,
        int stock, double price) {
return NULL;   // replace this
}

/* Find product */
/* Parameters:
 * start: first element in the linked list
 * code: product code to be found
 * 
 * Returns: Pointer to the first instance of product, or NULL if not found
 */
struct product *find_product(struct product *start, const char *code) {
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
return NULL;
}

/* Delete list */
/* Parameters:
 * start: first element in linked list
 * 
 * Returns: 1, when list has been deleted
 */
int delete_list(struct product *start) {
return 0;
}
