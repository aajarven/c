#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "products.h"


/*  From Aalto
 *
 * Write a simple program for book keeping a storage content. For every product in the storage, you will need to know 
 * its name, code, price and current stock amount. The required types are already defined in header files
 *
 * The operations for the storage handling include
 *     add a new item
 *     checking if the item exists in the storage
 *     removing product from the storage
 *     deleting the storage structures
 *
 * Data structure definition in products.h.  You are using a linked list with entry node in this version
 *
 */



void print_product(struct product *p)
{
    printf("%s (%s) -- stock: %d, price: %lf\n",
                p->title, p->code,
                p->stock, p->price);
}

int main()
{
    /*Feel free to modify this function */

    struct product_list list;
    struct product *p;

    init_list(&list);

    add_product(&list, "test", "1234", 1, 0.50);



    add_product(&list, "Product 1", "0000", 0, 10);
    add_product(&list, "Long name, isn't it", "1234567890", 10, 100);
    add_product(&list, "Product 3", "9999999", 0, 20);

    p = find_product(&list, "0000");
    if (p)
        print_product(p);
    else
        printf("Not found\n");

    int i=remove_product(&list, "0000");
    printf("Removed %d items\n", i);

    delete_list(&list);
}
