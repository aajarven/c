#include <stdlib.h>
#include "products.h"



/* initializes the argument list */
void init_list (struct product_list *list)
{
  list->head = NULL;
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
return NULL;   // replace this
}

/* Find product */
/* Parameters:
 * start: The head node
 * code: product code to be found
 * 
 * Returns: Pointer to the first instance of product, or NULL if not found
 */
struct product *find_product(struct product_list *start, const char *code) {
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
return 0;
}

/* Delete list */
/* Parameters:
 * start: list head
 *
 * Returns: 1, when list has been deleted
 */
int delete_list(struct product_list *listhead) {
return 0;
}
